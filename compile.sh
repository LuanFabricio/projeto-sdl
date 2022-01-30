#!usr/bin/zsh
mkdir -p objs
cd objs
g++ -c ../src/main.cpp ../src/init.cpp ../src/draw.cpp ../src/input.cpp ../src/game/ui.cpp ../src/game/keyboardHandler.cpp
g++ main.o init.o draw.o input.o ui.o keyboardHandler.o -lm -w -lSDL2 -lSDL2_ttf -o projeto.out 
mv projeto.out ../
cd ..
