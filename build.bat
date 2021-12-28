g++ -Wall -g -std=c++17 -c hafight.cpp
g++ -Wall -g -std=c++17 -c gamestate.cpp
g++ -Wall -g -std=c++17 -c raylibrenderer.cpp
g++ main.cpp -o game.exe hafight.o gamestate.o raylibrenderer.o lib/GGPO.lib -O2 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm && game.exe

