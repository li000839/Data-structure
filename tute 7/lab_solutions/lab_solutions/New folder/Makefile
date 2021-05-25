#
# created for COMP20007 Design of Algorithms 2017
# by Matt Farrugia <matt.farrugia@unimelb.edu.au>
#
# changed for COMP20007 Design of Algorithms 2020
# by Tobias Edwards <tobias.edwards@unimelb.edu.au>
#

# specifying the C Compiler and Compiler Flags for make to use
CC     = gcc
CFLAGS = -Wall -Wno-comment -std=c99

# exe name and a list of object files that make up the program
EXE    = main
OBJ    = main.o listForTask2.o graphForTask2.o graphalgsForTask2.o priorityqueueForTask2.o

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

graphalgsForTask2.o: graphalgsForTask2.c graphalgsForTask2.h graphForTask2.h
	$(CC) $(CFLAGS) -c graphalgsForTask2.c

graphForTask2.o: graphForTask2.c graphForTask2.h listForTask2.h
	$(CC) $(CFLAGS) -c graphForTask2.c

listForTask2.o: listForTask2.c listForTask2.h
	$(CC) $(CFLAGS) -c listForTask2.c

priorityqueueForTask2.o: priorityqueueForTask2.c priorityqueueForTask2.h
	$(CC) $(CFLAGS) -c priorityqueueForTask2.c

clean:
	rm -f $(OBJ) $(EXE)
