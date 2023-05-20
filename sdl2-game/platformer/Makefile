CC = gcc
.PHONY: all build clean

all: build
	./build/game

build:
	${CC} main.c -Iinclude -Iinclude/sdl -Iinclude/headers -Llib -o ./build/game -Wall -Wextra -pedantic -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

clean:
	rm -f ./build/game