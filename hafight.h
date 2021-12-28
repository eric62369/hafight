#ifndef _HAFIGHT_H
#define _HAFIGHT_H

#include "include/ggponet.h"

/*
 * hafightwar.h --
 *
 * Interface to the HAFight application.
 *
 */

enum HAFightInputs {
   INPUT_THRUST            = (1 << 0),
   INPUT_BREAK             = (1 << 1),
   INPUT_ROTATE_LEFT       = (1 << 2),
   INPUT_ROTATE_RIGHT      = (1 << 3),
   INPUT_FIRE              = (1 << 4),
   INPUT_BOMB              = (1 << 5),
};

void HAFight_Init(unsigned short localport, int num_players, GGPOPlayer *players, int num_spectators);
void HAFight_InitSpectator(unsigned short localport, int num_players, char *host_ip, unsigned short host_port);
void HAFight_DrawCurrentFrame();
void HAFight_AdvanceFrame(int inputs[], int disconnect_flags);
void HAFight_RunFrame();
void HAFight_Idle(int time);
void HAFight_DisconnectPlayer(int player);
void HAFight_Exit();

#define ARRAY_SIZE(n)      (sizeof(n) / sizeof(n[0]))
#define FRAME_DELAY        2

#endif
