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

#include "raylib.h"
#include "ggponet.h"
#include "hafight.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 fighters[2];
    fighters[0] = { (float)screenWidth/2 + 100, (float)screenHeight/2 };
    fighters[1] = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    unsigned short localport = 7000;
    int num_players = 2;
    GGPOPlayer players[num_players];

    HAFight_Init(localport, num_players, players, 0);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // if (IsKeyDown(KEY_RIGHT)) {
        //     fighters[0].x += 2.0f;
        //     fighters[1].x += 2.0f;
        // }
        // if (IsKeyDown(KEY_LEFT)) {
        //     fighters[0].x -= 2.0f;
        //     fighters[1].x -= 2.0f;
        // }
        // if (IsKeyDown(KEY_UP)) {
        //     fighters[0].y -= 2.0f;
        //     fighters[1].y -= 2.0f;
        // }
        // if (IsKeyDown(KEY_DOWN)) {
        //     fighters[0].y += 2.0f;
        //     fighters[1].y += 2.0f;
        // }

        
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        // BeginDrawing();

        //     ClearBackground(RAYWHITE);

        //     DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

        //     DrawCircleV(fighters[0], 25, MAROON);
        //     DrawCircleV(fighters[1], 25, BLUE);

        // EndDrawing();

        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}