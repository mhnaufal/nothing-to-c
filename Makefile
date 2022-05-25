CC = gcc
MOVE_TO_DB = cd not-redis

db: db_build
	${MOVE_TO_DB} && ./command.out $(filter-out $@,$(MAKECMDGOALS))

db_build:
	${MOVE_TO_DB} && ${CC} command.c -o command.out

%:
	@:

clean:
	rm -rf *.exe *.out
