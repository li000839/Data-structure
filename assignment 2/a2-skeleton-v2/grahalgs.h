#ifndef GRAPHALGS_H
#define GRAPHALGS_H

#include "graph.h"

int dfs(struct graph *graph);

void dfs_explore(struct graph *graph, int u, int *order, bool *visited, int *n_visited);

#endif
