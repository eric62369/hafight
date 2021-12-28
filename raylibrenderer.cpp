#include "raylibrenderer.h"
#include "include/raylib.h"

RaylibRenderer::RaylibRenderer()
{
   //
}

RaylibRenderer::~RaylibRenderer()
{
   //
}

void
RaylibRenderer::Draw(GameState &gs, NonGameState &ngs) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    DrawCircleV({ (float) gs._fighters[0].position.x, (float) gs._fighters[0].position.y }, 25, MAROON);
    DrawCircleV({ (float) gs._fighters[1].position.x, (float) gs._fighters[1].position.y }, 25, BLUE);

    EndDrawing();
}

void
RaylibRenderer::SetStatusText(const char *text)
{

}
