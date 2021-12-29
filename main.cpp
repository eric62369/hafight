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
#include <chrono>
#include <string.h>
#include "include/raylib.h"
#include "hafight.h"

using namespace std::chrono;

int main(int argc, char *argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    unsigned short localport = 7001;
    int num_players = 2;
    GGPOPlayer players[num_players];
    if (strncmp(argv[argc - 1], "0", 1)) {
        localport = 7000;
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