#include "raylibrenderer.h"
#include "include/raylib.h"
#include <string.h>

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

    DrawText(_status, 10, 10, 20, DARKGRAY);

    DrawCircleV({ (float) gs._fighters[0].position.x, (float) gs._fighters[0].position.y }, 12, MAROON);
    DrawCircleV({ (float) gs._fighters[1].position.x, (float) gs._fighters[1].position.y }, 12, BLUE);

    EndDrawing();
}

void
RaylibRenderer::SetStatusText(const char *text)
{
   strncpy(_status, text, sizeof(_status));
}
