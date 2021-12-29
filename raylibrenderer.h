#ifndef _RAYLIB_RENDERER_H_
#define _RAYLIB_RENDERER_H_

#include "renderer.h"

/*
 * renderer.h --
 *
 * A simple C++ renderer that uses GDI to render the game state.
 *
 */

class RaylibRenderer : public Renderer {
public:
   RaylibRenderer();
   ~RaylibRenderer();

   virtual void Draw(GameState &gs, NonGameState &ngs);
   virtual void SetStatusText(const char *text);

// protected:
//    void RenderChecksum(int y, NonGameState::ChecksumInfo &info);
//    void DrawFighter(int which, GameState &gamestate);
//    void DrawConnectState(Fighter &fighter, PlayerConnectionInfo &info);

   char           _status[1024];
};

#endif
