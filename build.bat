
g++ -Wall -g -std=c++17 vectorwar.cpp
g++ main.cpp -o game.exe -O2 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm && game.exe