#ifndef _GGPOUTIL_PERFMON_H
#define _GGPOUTIL_PERFMON_H

#include "include/ggponet.h"

int ggpoutil_perfmon_init();
void ggpoutil_perfmon_update(GGPOSession *ggpo, GGPOPlayerHandle players[], int num_players);
void ggpoutil_perfmon_toggle();


#endif 