/*
graph.c

Set of vertices and edges implementation.

Implementations for helper functions for graph construction and manipulation.

Skeleton written by Grady Fitzpatrick for COMP20007 Assignment 1 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "graph.h"
#include "utils.h"
#include "pq.h"
#include "list.h"
#include "grahalgs.h"

#define INITIALEDGES 32

struct edge;

/* Definition of a graph. */
struct graph {
  int numVertices;
  int numEdges;
  int allocedEdges;
  struct edge **edgeList;
  struct list **vertices;   // Array of adjacency Lists
};

/* Definition of an edge. */
struct edge {
  int start;
  int end;
};

struct graph *newGraph(int numVertices){
  struct graph *g = (struct graph *) malloc(sizeof(struct graph));
  assert(g);
  /* Initialise edges. */
  g->numVertices = numVertices;
  g->numEdges = 0;
  g->allocedEdges = 0;

  g->vertices = malloc(sizeof(struct list *) * numVertices);
  assert(g->vertices);
  for (int i = 0; i < numVertices; i++) {
    g->vertices[i] = new_list();
  }

  g->edgeList = NULL;
  return g;
}

/* Adds an edge to the given graph. */
void addEdge(struct graph *g, int start, int end){
  assert(g);
  struct edge *newEdge = NULL;
  /* Check we have enough space for the new edge. */
  if((g->numEdges + 1) > g->allocedEdges){
    if(g->allocedEdges == 0){
      g->allocedEdges = INITIALEDGES;
    } else {
      (g->allocedEdges) *= 2;
    }
    g->edgeList = (struct edge **) realloc(g->edgeList,
      sizeof(struct edge *) * g->allocedEdges);
    assert(g->edgeList);
  }

  /* Create the edge */
  newEdge = (struct edge *) malloc(sizeof(struct edge));
  assert(newEdge);
  newEdge->start = start;
  newEdge->end = end;

  /* Add the edge to the list of edges. */
  g->edgeList[g->numEdges] = newEdge;
  (g->numEdges)++;

  assert(g != NULL);
  // Assert that u and v are valid indices
  assert(start >= 0 && start < g->numVertices);
  assert(end >= 0 && end < g->numVertices);
   
  list_add_end(g->vertices[start], end);
  list_add_end(g->vertices[end], start);
}

/* Frees all memory used by graph. */
void freeGraph(struct graph *g){
  int i;
  for(i = 0; i < g->numEdges; i++){
    free((g->edgeList)[i]);
  }
  if(g->edgeList){
    free(g->edgeList);
  }
  free(g);
}

/* Finds:
  - Number of connected subnetworks (before outage) (Task 2)
  - Number of servers in largest subnetwork (before outage) (Task 3)
  - SIDs of servers in largest subnetwork (before outage) (Task 3)
  - Diameter of largest subnetworks (after outage) (Task 4)
  - Number of servers in path with largest diameter - should be one more than
    Diameter if a path exists (after outage) (Task 4)
  - SIDs in path with largest diameter (after outage) (Task 4)
  - Number of critical servers (before outage) (Task 7)
  - SIDs of critical servers (before outage) (Task 7)
*/
struct solution *graphSolve(struct graph *g, enum problemPart part,
  int numServers, int numOutages, int *outages){
  struct solution *solution = (struct solution *)
    malloc(sizeof(struct solution));
  assert(solution);
  /* Initialise solution values */
  initaliseSolution(solution);
  if(part == TASK_2){
    /* IMPLEMENT TASK 2 SOLUTION HERE */
    solution->connectedSubnets = dfsTask2(g);
  } else if(part == TASK_3) {
    /* IMPLEMENT TASK 3 SOLUTION HERE */
    // compare if there are two same size subnetworks
    int *subnetSize = malloc(sizeof(int));
    int **subnets = dfsTask3(g, subnetSize);
    solution->connectedSubnets = dfsTask2(g);

    solution->largestSubnet = sizeLargestSubnetwork(subnetSize, solution->connectedSubnets);
    solution->largestSubnetSIDs = LargestSubnetwork(subnets, subnetSize, solution->connectedSubnets);
  } else if(part == TASK_4) {
    /* IMPLEMENT TASK 4 SOLUTION HERE */
    solution->postOutageDiameter = 0;
    solution->postOutageDiameterCount = 0;
    solution->postOutageDiameterSIDs = NULL;
  } else if(part == TASK_7) {
    /* IMPLEMENT TASK 7 SOLUTION HERE */
    solution->criticalServerCount = 0;
    solution->criticalServerSIDs = NULL;
  }
  return solution;
}

int graph_num_vertices(struct graph *graph) {
  return graph->numVertices;
}

int graph_out_degree(struct graph *graph, int start) {
  return list_size(graph->vertices[start]);
}


int graph_get_neighbours(struct graph *graph, int u, int *neighbours, int n) {
  assert(graph != NULL);
  assert(neighbours != NULL);

  struct list *adjacentcy_list = graph->vertices[u];

  // There's only room for n vertex indices in the array neighbours, so if
  // u has more neighbours than this then print an error
  if (list_size(adjacentcy_list) > n) {
    fprintf(stderr,
      "Error: graph_get_neighbours() not provided with a big enough array\n");
    exit(EXIT_FAILURE);
  }

  // Note: We added the ListIterator type for this purpose
  ListIterator *neighbour_iterator = new_list_iterator(adjacentcy_list);
  int i = 0;
  while (list_iterator_has_next(neighbour_iterator)) {
    neighbours[i] = list_iterator_next(neighbour_iterator);
    i++;
  }
  free_list_iterator(neighbour_iterator);

  // #1 sort order of neighbours;
  neighbours = quicksort(neighbours, n);
  return i;
}