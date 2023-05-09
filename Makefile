CC = gcc
MOVE_TO_DB = cd not-redis
MOVE_TO_KOMPILE = cd compiler
MOVE_TO_SHELL = cd shell
MOVE_TO_TIC = cd toe-tac-tic
MOVE_TO_HANG = cd hangman

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

tic: tic_build
	${MOVE_TO_TIC} && ./tic.out $(filter-out $@,$(MAKECMDGOALS))

tic_build:
	${MOVE_TO_TIC} && ${CC} tic.c -o tic.out -Wall -Wextra -pedantic

hang: hang_build
	${MOVE_TO_HANG} && ./hang.out $(filter-out $@,$(MAKECMDGOALS))

hang_build:
	${MOVE_TO_HANG} && ${CC} hang.c -o hang.out -Wall -Wextra -pedantic

clean:
	rm -rf *.exe *.out *.o
