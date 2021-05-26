#ifndef GRAPHALGS_H
#define GRAPHALGS_H

#include "graph.h"

int dfsTask2(struct graph *graph);

int **dfsTask3(struct graph *graph, int *subnetSize);

void dfs_explore(struct graph *graph, int u, int *order, bool *visited, int *n_visited);

int *quicksort(int *neighbours, int n_neighbours);


#endif
