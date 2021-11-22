# Name of compiled file
prog = main

# Object files
OBJ = main.o tree.o

# Compiler oprional setings
OPT = -std=c99 -Wall -Werror -pedantic -O2

# Other targets
.PHONY: clear
.PHONY: zip

# Make execute
${prog}: ${OBJ}
	gcc ${OPT} ${OBJ} -o ${prog}

# Make clear execute
clear:
	rm -f *.o ${prog}

# Make zip execute
zip:
	zip tree.zip Makefile main.c tree.c tree.h

# Object files compile
main.o: main.c tree.h
	gcc main.c -c ${OPT}

tree.o: tree.c tree.h
	gcc tree.c -c ${OPT}
