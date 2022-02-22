#!usr/bin/zsh
mkdir -p objs
cd objs
g++ -c ../src/main.cpp ../src/init.cpp ../src/draw.cpp ../src/input.cpp ../src/util.cpp ../src/game/ui.cpp ../src/game/buttonHandler.cpp ../src/game/keyboardHandler.cpp ../src/game/entity.cpp ../src/game/scenes/fight.cpp
g++ main.o init.o draw.o input.o util.o ui.o buttonHandler.o keyboardHandler.o entity.o fight.o -lm -w -lSDL2 -lSDL2_ttf -lSDL2_image -o projeto.out 
mv projeto.out ../
cd ..
