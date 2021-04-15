#include "graph.h"
#include "pq.h"

/* find the cost of pure cable plan */
int findCableTotal(struct graph *g, int start);

/* give the shortest cost of the path by dijkstra */
void dijkstra(struct graph *g, int start);

/* initialize a priority queue with a start vertex*/
struct pq *initPQ(struct graph *g, struct pq *PriorityQueue, int start);

/* eject min item from pq and add into finalPath as final result*/
void addFinalPath(int *finalPath, struct path *item, int count);

/* update total priority and one step of path */
void update(struct pq *PriorityQueue, int prev, int cur, int priority);