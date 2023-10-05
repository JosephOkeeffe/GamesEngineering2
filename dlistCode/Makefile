

# Joseph O'Keeffe
# 29/9/23
# Licensed under GPLv3
CFILES=stuff.c 
OBJFILES=stuff.o
HFILES=minunit.h
CC= gcc
EXEFILE=exe
FLAGS= -Wall -g -O0

%.o: %.c
	$(CC) -Wall -c $< -o $@ 

EXE: $(OBJFILES) $(HFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(EXEFILE)

CLEAN: 
	rm *.o

INSTALL:
	cp $(EXEFILE) home/osboxes/bin/