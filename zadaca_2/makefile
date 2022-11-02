SRC=$(wildcard src/*c)
MAINS=$(wildcard exesrc/*.c)

#every test file has to begin with test (ex. test_file.c, test_sth.c)
TESTS=$(wildcard exesrc/test*.c)

MAIN=exesrc/main.c

#$(patsubst pattern,replacement,text)
OBJ=$(patsubst %c, %o, $(SRC)) $(patsubst %c, %o, $(MAIN))
#OBJ=$(patsubst %c, %o, $(SRC)) MAIN
INC=inc/

CFLAGS=-I $(INC)
#EXE=exe/app.elf
EXE=exe/app.elf $(patsubst exesrc%c, exe%elf, $(TESTS))


.SECONDARY:

all: $(EXE)

%.elf: $(OBJ)
	gcc $(OBJ) -lm -o $@

%.o: %.c
	gcc -c $< $(CFLAGS) -o $@

clean:
	rm -f $(OBJ) $(EXE)
