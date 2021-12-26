#include <stdio.h>
#if defined(_DEBUG)
#   include <crtdbg.h>
#endif
#include "vectorwar.h"
#include "ggpo_perfmon.h"
#include "raylib.h"

int wWinMain(
    unsigned short local_port,
    int num_players,
    int argc
)
{
   int offset = 1, local_player = 0;
   wchar_t wide_ip_buffer[128];
   unsigned int wide_ip_buffer_size = (unsigned int)ARRAYSIZE(wide_ip_buffer);
   POINT window_offsets[] = {
      { 64,  64 },   // player 1
      { 740, 64 },   // player 2
      { 64,  600 },  // player 3
      { 740, 600 },  // player 4
   };
   
#if defined(_DEBUG)
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

   if (argc < 3) {
      Syntax();
      return 1;
   }
   if (num_players < 0 || argc < offset + num_players) {
      Syntax();
      return 1;
   }
   if (wcscmp(__wargv[offset], L"spectate") == 0) {
      char host_ip[128];
      unsigned short host_port;
      if (swscanf_s(__wargv[offset+1], L"%[^:]:%hu", wide_ip_buffer, wide_ip_buffer_size, &host_port) != 2) {
         Syntax();
         return 1;
      }
      wcstombs_s(nullptr, host_ip, ARRAYSIZE(host_ip), wide_ip_buffer, _TRUNCATE);
      VectorWar_InitSpectator(hwnd, local_port, num_players, host_ip, host_port);
   } else {
      GGPOPlayer players[GGPO_MAX_SPECTATORS + GGPO_MAX_PLAYERS];

      int i;
      for (i = 0; i < num_players; i++) {
         const wchar_t *arg = __wargv[offset++];

         players[i].size = sizeof(players[i]);
         players[i].player_num = i + 1;
         if (!_wcsicmp(arg, L"local")) {
            players[i].type = GGPO_PLAYERTYPE_LOCAL;
            local_player = i;
            continue;
         }
         
         players[i].type = GGPO_PLAYERTYPE_REMOTE;
         if (swscanf_s(arg, L"%[^:]:%hd", wide_ip_buffer, wide_ip_buffer_size, &players[i].u.remote.port) != 2) {
            Syntax();
            return 1;
         }
         wcstombs_s(nullptr, players[i].u.remote.ip_address, ARRAYSIZE(players[i].u.remote.ip_address), wide_ip_buffer, _TRUNCATE);
      }
      // these are spectators...
      int num_spectators = 0;
      while (offset < argc) {
         players[i].type = GGPO_PLAYERTYPE_SPECTATOR;
         if (swscanf_s(__wargv[offset++], L"%[^:]:%hd", wide_ip_buffer, wide_ip_buffer_size, &players[i].u.remote.port) != 2) {
            Syntax();
            return 1;
         }
         wcstombs_s(nullptr, players[i].u.remote.ip_address, ARRAYSIZE(players[i].u.remote.ip_address), wide_ip_buffer, _TRUNCATE);
         i++;
         num_spectators++;
      }

      VectorWar_Init(hwnd, local_port, num_players, players, num_spectators);
   }
   RunMainLoop(hwnd);
   VectorWar_Exit();
   WSACleanup();
   DestroyWindow(hwnd);
   return 0;
}