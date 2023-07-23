CC = gcc
C_FLAGS = -Wall -Wextra -pedantic -std=c11 -m64
RAYLIB_FLAGS = -lmingw32 -lraylib -lopengl32 -lgdi32 -lwinmm
RAYLIB_LIBS = -isystem include -isysteminclude/raylib -Llib
FILES = ./src/main.c ./src/game.c ./src/util.c # we define the files manually to prevent VSCode to being a FUCKED UP code editor
.PHONY: all build run build clean release

all: build release

run: build
	./build/game

build:
	${CC} ${FILES} ${RAYLIB_LIBS} -o ./build/game ${C_FLAGS} -O0 ${RAYLIB_FLAGS}

release:
	${CC} ${FILES} ${RAYLIB_LIBS} -o ./build/release/game ${C_FLAGS} -Ofast ${RAYLIB_FLAGS}

clean:
	rm -f ./build/game ./build/release/game
