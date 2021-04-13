#include "graph.h"

int findCableTotal(struct graph *g, int start);

struct pq *initPQ(struct graph *g);

struct edge **findAlledge(struct graph *g, int vertex);

int findLowestCost(struct graph *g, int vertex);