SRC=$(wildcard src/*c)
#MAINS=$(wildcard exesrc/*.c)

#every test file has to begin with test (ex. test_file.c, test_sth.c)
TESTS=$(wildcard exesrc/test*.c)

MAIN=exesrc/main.c

#$(patsubst pattern,replacement,text)
OBJ=$(patsubst %c, %o, $(SRC)) $(patsubst %c, %o, $(TESTS)) $(patsubst %c, %o, $(MAIN)) 

OBJMAIN= $(patsubst %c, %o, $(SRC)) $(patsubst %c, %o, $(MAIN)) 
OBJTEST=  $(patsubst %c, %o, $(TESTS))

OBJSRC=$(patsubst %c, %o, $(SRC))



INC=inc/

CFLAGS=-I $(INC)

EXEMAIN=exe/app.elf 
EXETEST=$(patsubst exesrc%c, exe%elf, $(TESTS))




all: $(EXEMAIN)
test:  $(EXETEST)

$(EXEMAIN): $(OBJMAIN) 
	gcc $(OBJMAIN) -lm -o $@
%.o: %.c
	gcc -c $< $(CFLAGS) -o $@

 
$(EXETEST): $(OBJTEST)
	gcc $(OBJSRC) $(patsubst exe%elf, exesrc%o, $@) -lm -o $@
$(OBJTEST): $(OBJSRC)
%o: %.c
	gcc -c $< $(CFLAGS) -o $@

clean:
	rm -f $(OBJ) $(EXETEST) $(EXEMAIN) $(OBJTEST) $(EXETEST)
