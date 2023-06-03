CC = gcc
C_FLAGS = -Wall -Wextra -pedantic
SDL_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
SDL_LIBS = -Iinclude -Iinclude/sdl2 -Iinclude/headers -Llib
FILES = main.c map.c entity.c game.c util.c
.PHONY: all debug run bin clean

all: debug release

run: debug
	./bin/game

debug:
	${CC} ${FILES} ${SDL_LIBS} -o ./bin/game ${C_FLAGS} ${SDL_FLAGS}

release:
	${CC} ${FILES} -O3 ${SDL_LIBS} -o ./bin/release/game ${C_FLAGS} ${SDL_FLAGS}

clean:
	rm -f ./bin/game ./bin/release/game
