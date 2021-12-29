#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

/*
 * gamestate.h --
 *
 * Encapsulates all the game state inside
 * a single structure.  This makes it trivial to implement our GGPO
 * save and load functions.
 */

#define PI                    ((double)3.1415926)
#define STARTING_HEALTH       100
#define ROTATE_INCREMENT        3
#define FIGHTER_RADIUS            15
#define FIGHTER_WIDTH              8
#define FIGHTER_TUCK               3
#define FIGHTER_THRUST             1
#define FIGHTER_MAX_THRUST         1
#define FIGHTER_BREAK_SPEED        0.6
#define BULLET_SPEED            5
#define MAX_BULLETS             30
#define BULLET_COOLDOWN         8
#define BULLET_DAMAGE           10

#define MAX_FIGHTERS               2

struct Position {
   double x, y;
};

struct Velocity {
   double dx, dy;
};

struct Fighter {
   Position position;
   Velocity velocity;
   int      radius;
   int      heading;
   int      health;
   int      speed;
   int      cooldown;
   int      score;
};

struct GameState {
   void Init(int num_players);
   void GetFighterAI(int i, double *heading, double *thrust, int *fire);
   void ParseFighterInputs(int inputs, int i, double *heading, double *thrust, int *fire);
   void MoveFighter(int i, double x, double y);
   void Update(int inputs[], int disconnect_flags);

   int         _framenumber;
   int         _num_fighters;
   Fighter     _fighters[MAX_FIGHTERS];
};

#endif
