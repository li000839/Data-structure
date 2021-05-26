#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "debug.h"
#include "grahalgs.h"
#include "list.h"
#include "graph.h"


#define INFTY -1
#define NO_PREV -1

// Runs a depth first search on the given graph, returning a dynamically
// allocated array of integers representing the order in which the DFS
// visits the nodes in the graph.
//
// The resultant array will be of size n_vertices and must be freed after use.
int dfsTask2(struct graph *graph) {
  int n = graph_num_vertices(graph);
  int *order = malloc(sizeof(int) * n);
  assert(order);
  // Use calloc to allocate and set all memory to 0
  bool *visited = calloc(n, sizeof(bool));
  assert(visited);

  int n_visited = 0;
  int connected_subnetworks = 0;

  for (int u = 0; u < n; u++) {
    if (!visited[u]) {
      connected_subnetworks++;
      // record traversal of each loop == record update of order
      // #2
      dfs_explore(graph, u, order, visited, &n_visited);
    }
  }

  free(visited);
  return connected_subnetworks;
}

// Recursive explore function which explores from node u in the graph.
// order and visited are arrays of length n_vertices, n_visited is a pointer
// to the number of nodes which have already been visited.
//
// order[i] == k means that vertex k was visited ith in the order, while
// visited[i] == true means that node i has been visited
void dfs_explore(struct graph *graph, int u, int *order, bool *visited, int *n_visited) {
  visited[u] = true;
  order[*n_visited] = u;
  (*n_visited)++;

  // Create an array to hold the neighbors of u
  int n_neighbours = graph_out_degree(graph, u);
  int *neighbours = malloc(sizeof(int) * n_neighbours);
  // Retrieve these neighbours from the graph
  graph_get_neighbours(graph, u, neighbours, n_neighbours);

  int v;
  for (int i = 0; i < n_neighbours; i++) {
    v = neighbours[i];
    if (!visited[v]) {
      dfs_explore(graph, v, order, visited, n_visited);
    }
  }

  free(neighbours);
}

int *quicksort(int *neighbours, int n_neighbours) {
  for (int i = 1; i < n_neighbours; i++) {
    int temp = neighbours[i];
    int j = i - 1;
    while (j >= 0 && temp < neighbours[j]) {
      neighbours[j + 1] = neighbours[j];
      j--;
    }
    neighbours[j + 1] = temp;
  }
  return neighbours;
}

int **dfsTask3(struct graph *graph) {
  int n = graph_num_vertices(graph);
  int *order = malloc(sizeof(int) * n);
  assert(order);
  // Use calloc to allocate and set all memory to 0
  bool *visited = calloc(n, sizeof(bool));
  assert(visited);

  int n_visited = 0;
  int connected_subnetworks = 0;

  int row = 0;
  int col = 1;
  int **subnets = (int**)malloc(sizeof(int*) * row);  
  for (i = 0;i < row;i++) {
    subnets[i] = (int*)malloc(sizeof(int) * col);
  }
  for (int u = 0; u < n; u++) {
    if (!visited[u]) {
      connected_subnetworks++;
      dfs_explore(graph, u, order, visited, &n_visited);
      // record traversal of each loop == record update of order  
      // #2
      row++;
    }
  }
  
  
  free(visited);
  return subnets;
}