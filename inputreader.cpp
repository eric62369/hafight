#include "stdio.h"
#include "include/raylib.h"
#include "inputreader.h"

/*
 * ReadInputs --
 *
 * Read the inputs for player 1 from the keyboard.  We never have to
 * worry about player 2.  GGPO will handle remapping his inputs 
 * transparently.
 */
int
ReadInputs()
{
   static const struct {
      int      key;
      int      input;
   } inputtable[] = {
      { KEY_W,       INPUT_THRUST },
      { KEY_D,     INPUT_BREAK },
      { KEY_A,     INPUT_ROTATE_LEFT },
      { KEY_S,    INPUT_ROTATE_RIGHT },
      { KEY_J,         INPUT_FIRE },
      { KEY_K,         INPUT_BOMB },
   };
   int i, inputs = 0;

   for (i = 0; i < (int) (sizeof(inputtable) / sizeof(inputtable[0])); i++) {
      if (IsKeyDown(inputtable[i].key)) {
      inputs |= inputtable[i].input;
      }
   }
   return inputs;
}
