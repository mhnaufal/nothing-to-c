hello:
	echo "Hello from Makefile"

CC = gcc
MOVE_TO_DB = cd database

db: db_build
	${MOVE_TO_DB} && ./sql.o

db_build:
	${MOVE_TO_DB} && ${CC} sql.c -o sql.o

clean:
	rm *.exe *.out
