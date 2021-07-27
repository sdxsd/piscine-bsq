debug:
	clang -Wall -Wextra -Werror -g *.c
all: program 
program:
	clang -Wall -Wextra -Werror *.c

