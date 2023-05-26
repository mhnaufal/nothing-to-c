CC = gcc
C_FLAGS = -Wall -Wextra -pedantic
SDL_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
SDL_LIBS = -Iinclude -Iinclude/sdl -Iinclude/headers -Llib
.PHONY: all debug run bin clean

all: debug release

run: debug
	./bin/game

debug:
	${CC} main.c ${SDL_LIBS} -o ./bin/game ${C_FLAGS} ${SDL_FLAGS}

release:
	${CC} main.c -O3 ${SDL_LIBS} -o ./bin/release/game ${C_FLAGS} ${SDL_FLAGS}

clean:
	rm -f ./bin/game ./bin/release/game
