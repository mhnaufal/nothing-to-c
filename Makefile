CC = gcc
MOVE_TO_DB = cd not-redis
MOVE_TO_KOMPILE = cd compiler

db: db_build
	${MOVE_TO_DB} && ./command.out $(filter-out $@,$(MAKECMDGOALS))

db_build:
	${MOVE_TO_DB} && ${CC} command.c -o command.out -Wall -Wextra -pedantic

%:
	@:

kompile: kompile_build
	${MOVE_TO_KOMPILE} && ./parser.out $(filter-out $@,$(MAKECMDGOALS))

kompile_build:
	${MOVE_TO_KOMPILE} && ${CC} parser.c -o parser.out -Wall -Wextra -pedantic

clean:
	rm -rf *.exe *.out
