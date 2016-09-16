#Compiler
CC=gcc

#Compiler Flags
CFLAGS = -g -Wall --std=c99

#Source code files are named problemx.c where x is the problem number
#Executables will be named problemx where x is the problem number
SOURCE = problem

NUMBERS = 1 2 3 4 5 8

PROBLEMS := $(foreach number, $(NUMBERS), $(SOURCE)$(number)) 

all: $(PROBLEMS)

$($(PROBLEMS)$(NUMBERS)):
	$(CC) $(CFLAGS) -o $(PROBLEMS) $(PROBLEMS).c

clean:
	rm $(SOURCE)?
