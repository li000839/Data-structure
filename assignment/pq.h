/*
pq.h

Visible structs and functions for priority queues.

Skeleton written by Grady Fitzpatrick for COMP20007 Assignment 1 2021
*/
/* The priority queue. */
struct path {
  int vertex;
  int *prevcur;
  int cost;
};

struct pq {
  int count;       // length of pq
  int allocated;   // to increase size of pq, no other function
  struct path **queue;    // 2d list of overall path from start to each point
  int *priorities; // list of overall distance from start to each point
};

/* Get a new empty priority queue. */
struct pq *newPQ();

/* Add an item to the priority queue - cast pointer to (void *). */
/* struct pq *pq = priority queue 
   int *item = a list of overall path from start to vertex
   int priority = overall distance from start to vertex*/
void enqueue(struct pq *pq, int *item, int priority);

/* Take the smallest item from the priority queue - cast pointer back to
  original type. */
struct path *deletemin(struct pq *pq);

/* Returns 1 if empty, 0 otherwise. */
int empty(struct pq *pq);

/* Remove all items from priority queue (doesn't free) and free the queue. */
void freePQ(struct pq *pq);
