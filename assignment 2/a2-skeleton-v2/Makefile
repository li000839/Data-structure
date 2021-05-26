# Build targets
# lm - link math library library. required if you use math.h functions (commonly
# linked by default on mac).

# specifying the C Compiler and Compiler Flags for make to use
CC     = gcc
CFLAGS = -Wall -Wno-comment -std=c99 -g

task2: task2.o utils.o graph.o pq.o list.o grahalgs.o
	$(CC) $(CFLAGS) -o task2 task2.o utils.o graph.o pq.o list.o grahalgs.o -lm

task3: task3.o utils.o graph.o pq.o list.o
	$(CC) $(CFLAGS) -o task3 task3.o utils.o graph.o pq.o list.o -lm

task4: task4.o utils.o graph.o pq.o list.o
	$(CC) $(CFLAGS) -o task4 task4.o utils.o graph.o pq.o list.o -lm

task7: task7.o utils.o graph.o pq.o list.o
	$(CC) $(CFLAGS) -o task7 task7.o utils.o graph.o pq.o list.o -lm

task2.o: task2.c graph.h utils.h
	$(CC) $(CFLAGS) -c task2.c

task3.o: task3.c graph.h utils.h
	$(CC) $(CFLAGS) -c task3.c

task4.o: task4.c graph.h utils.h
	$(CC) $(CFLAGS) -c task4.c

task7.o: task7.c graph.h utils.h
	$(CC) $(CFLAGS) -c task7.c

utils.o: utils.c utils.h graph.h
	$(CC) $(CFLAGS) -c utils.c

graph.o: graph.c graph.h pq.h utils.h
	$(CC) $(CFLAGS) -c graph.c

pq.o: pq.c pq.h
	$(CC) $(CFLAGS) -c pq.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

grahalgs.o: grahalgs.c grahalgs.h graph.h
	$(CC) $(CFLAGS) -c grahalgs.c