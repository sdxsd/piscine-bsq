all: program clean

program:
	clang -Wall -Wextra -Werror *.c -o bsq

clean: 
	rm bsq
