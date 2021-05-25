/* * * * * * *
 * Main function providing functionality to read in a graph and test
 * a number of graph algorithms.
 *
 * created for COMP20007 Design of Algorithms 2020
 * by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

#include <stdio.h>
#include <stdlib.h>

#include "graphForTask2.h"
#include "graphalgsForTask2.h"
#include "priorityqueueForTask2.h"

// Read in a graph from stdin where the input format is:
//
// t w n m
// u_1 v_1 w_1
// ...
// u_m v_m w_m
//
// Where
//  - t is either U or D depending on whether the graph is (U)ndirected
//    or (D)irected,
//  - w is either U or W depending on whether the graph is (U)nweighted or
//    (W)eighted.
//  - n is the number of vertices -- the nodes are labelled 0 to n - 1
//  - m is the number edges
//  - each (u_i, v_i) is an edge (between node u_i and v_i)
//  - each w_i is only present in a weighted graph (i.e., when w = W)
//    and indicates the weight of each edge. w_i can be negative.
//
// Returns the read in graph or NULL if the input was malformed.
GraphForTask2 *read_graph_from_stdin(char *filename);

int main(int argc, char **argv) {
  GraphForTask2 *graph = read_graph_from_stdin(argv[1]);
  printf("Read in the following graph:\n");
  graph_print_adjacency_lists(graph);

  // Run the dfs algorithm on the read in graph
  int *dfs_order = dfs(graph);

  // Print out the order in which the nodes were visited in the dfs
  printf("DFS Order:");
  for (int i = 0; i < graph_num_vertices(graph); i++) {
    printf(" %d", dfs_order[i]);
  }
  printf("\n");

  free(dfs_order);
  dfs_order = NULL;

  // Run the dfs algorithm on the read in graph
  int *bfs_order = bfs(graph);

  // Print out the order in which the nodes were visited in the dfs
  printf("BFS Order:");
  for (int i = 0; i < graph_num_vertices(graph); i++) {
    printf(" %d", bfs_order[i]);
  }
  printf("\n");

  free(bfs_order);
  bfs_order = NULL;

  int *from = calloc(graph_num_vertices(graph), sizeof(int));
  int *to = calloc(graph_num_vertices(graph), sizeof(int));

  if (!prims(graph, from, to)) {
    printf("Couldn't find an MST using Prim's algorithm.\n");
  } else {
    printf("Edges in the MST:");
    for (int i = 0; i < graph_num_vertices(graph) - 1; i++) {
      printf(" (%d, %d)", from[i], to[i]);
    }
    printf("\n");
  }

  free(from);
  from = NULL;
  free(to);
  to = NULL;

  int *dist = calloc(graph_num_vertices(graph), sizeof(int));

  dijkstras(graph, 0, dist);
  printf("Shortest distances from 0:\n");
  for (int i = 0; i < graph_num_vertices(graph); i++) {
    printf("  to %d: %d\n", i, dist[i]);
  }

  free(dist);
  dist = NULL;

  return 0;
}

// Read in a graph from stdin where the input format is:
//
// t w n m
// u_1 v_1 w_1
// ...
// u_n v_n w_n
//
// Where
//  - t is either U or D depending on whether the graph is (U)ndirected
//    or (D)irected,
//  - w is either U or W depending on whether the graph is (U)nweighted or
//    (W)eighted.
//  - n is the number of vertices -- the nodes are labelled 0 to n - 1
//  - m is the number edges
//  - each (u_i, v_i) is an edge (between node u_i and v_i)
//  - each w_i is only present in a weighted graph (i.e., when w = W)
//    and indicates the weight of each edge. w_i can be negative.
//
// Returns the read in graph or NULL if the input was malformed.
GraphForTask2 *read_graph_from_stdin(char *filename) {
  char t, w;
  int n, m;
  int u_i, v_i, w_i;
  bool directed, weighted;

  freopen(filename, "r", stdin);
  // read in the first line of input
  if (scanf("%c %c %d %d", &t, &w, &n, &m) != 4) {
    return NULL;
  }

  // make sure t is valid
  if (t == 'U' || t == 'u') {
    directed = false;
  } else if (t == 'D' || t == 'd') {
    directed = true;
  } else {
    return NULL;
  }

  // make sure w is valid
  if (w == 'U' || w == 'u') {
    weighted = false;
  } else if (w == 'W' || w == 'w') {
    weighted = true;
  } else {
    return NULL;
  }

  GraphForTask2 *graph = new_graph(n, directed);

  // m times read in a line of input and process the edge given
  for (int i = 0; i < m; i++) {
    if (weighted && (scanf("%d %d %d", &u_i, &v_i, &w_i) == 3)) {
      graph_add_edge(graph, u_i, v_i, w_i);
    } else if (!weighted && (scanf("%d %d", &u_i, &v_i) == 2)) {
      graph_add_edge(graph, u_i, v_i, 1);
    } else {
      // something went wrong
      free_graph(graph);
      return NULL;
    }
  }

  fclose(stdin);
  return graph;
}
