g++ -Wall -g -std=c++17 -c hafight.cpp
g++ -Wall -g -std=c++17 -c gamestate.cpp
g++ -Wall -g -std=c++17 -c raylibrenderer.cpp
g++ -Wall -g -std=c++17 -c inputreader.cpp
g++ main.cpp -o game.exe hafight.o gamestate.o raylibrenderer.o inputreader.o lib/GGPO.lib -O0 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

start game.exe 0
game.exe 1
