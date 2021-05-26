#ifndef GRAPHALGS_H
#define GRAPHALGS_H

#include "graph.h"

int dfsTask2(struct graph *graph);

struct subnet *dfsTask3(struct graph *graph);

void dfs_explore(struct graph *graph, int u, int *order, bool *visited, int *n_visited);

int *quicksort(int *neighbours, int n_neighbours);

int *LargestSubnetwork(int **subnets, int *subnetSize, int connectedSubnets);

int sizeLargestSubnetwork(int *subnetSize, int connectedSubnets);

#endif
