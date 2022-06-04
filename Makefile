CC = gcc
MOVE_TO_DB = cd not-redis
MOVE_TO_KOMPILE = cd compiler
MOVE_TO_SHELL = cd shell

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

shell: shell_build
	${MOVE_TO_SHELL} && ./shell.out $(filter-out $@,$(MAKECMDGOALS))

shell_build:
	${MOVE_TO_SHELL} && ${CC} shell.c -o shell.out -Wall -Wextra -pedantic

clean:
	rm -rf *.exe *.out
