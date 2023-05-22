CC = gcc
.PHONY: all bin clean

all: debug release

run: debug
	./bin/game

debug:
	${CC} main.c -Iinclude -Iinclude/sdl -Iinclude/headers -Llib -o ./bin/game -Wall -Wextra -pedantic -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

release:
	${CC} main.c -O3 -Iinclude -Iinclude/sdl -Iinclude/headers -Llib -o ./bin/release/game -Wall -Wextra -pedantic -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

clean:
	rm -f ./bin/game ./bin/release/game
