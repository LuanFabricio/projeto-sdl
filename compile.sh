#!usr/bin/zsh
mkdir -p objs
cd objs
g++ -c ../src/main.cpp ../src/init.cpp ../src/draw.cpp ../src/input.cpp ../src/util.cpp ../src/game/ui.cpp ../src/game/keyboardHandler.cpp ../src/game/entity.cpp
g++ main.o init.o draw.o input.o util.o ui.o keyboardHandler.o entity.o -lm -w -lSDL2 -lSDL2_ttf -lSDL2_image -o projeto.out 
mv projeto.out ../
cd ..
