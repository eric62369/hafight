/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <algorithm>
#include <stdio.h>
#include <wchar.h>
#include <chrono>
#include <string.h>
#include "include/raylib.h"
#include "hafight.h"

#define ARRAYSIZE(a) ((sizeof(a) / sizeof(*(a))) / static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

using namespace std::chrono;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Needs 3 arguments\n");
        return 1;
    }
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    unsigned short localport;
    int num_players = 2;
    GGPOPlayer players[2];
    if (strncmp(argv[1], "0", 1)) {
        localport = 7000;

        players[0].size = sizeof(players[0]);
        players[0].player_num = 1;
        players[0].type = GGPO_PLAYERTYPE_LOCAL;
        
        players[1].size = sizeof(players[1]);
        players[1].player_num = 2;
        players[1].type = GGPO_PLAYERTYPE_REMOTE;
        players[1].u.remote.port = 7001;
        
        strncpy(players[1].u.remote.ip_address, argv[2], sizeof(players[1].u.remote.ip_address));
        
        printf("%s\n", players[1].u.remote.ip_address);
        printf("%d\n", players[1].u.remote.port);
    } else {
        localport = 7001;

        players[1].size = sizeof(players[1]);
        players[1].player_num = 2;
        players[1].type = GGPO_PLAYERTYPE_LOCAL;
        
        players[0].size = sizeof(players[0]);
        players[0].player_num = 1;
        players[0].type = GGPO_PLAYERTYPE_REMOTE;
        players[0].u.remote.port = 7000;

        strncpy(players[0].u.remote.ip_address, argv[2], sizeof(players[0].u.remote.ip_address));

        printf("%s\n", players[0].u.remote.ip_address);
        printf("%d\n", players[0].u.remote.port);
    }


    HAFight_Init(localport, num_players, players, 0);

    // Main game loop
    int start, next, now;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        now = duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count();
        HAFight_Idle(std::max(0, next - now - 1));
        if (now >= next) {
            HAFight_RunFrame();
            next = now + (1000 / 60);
        }
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    HAFight_Exit();
    //--------------------------------------------------------------------------------------

    return 0;
}