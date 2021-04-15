#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "dijikstra.h"
#include "graph.h"
#include "pq.h"

#define INFINITY 100000

int
findCableTotal(struct graph *g, int start) {
    
    dijkstra(g, start);

    calculateCost(QueueOftotalPath);
    
    return;
}

dijkstra(struct graph *g, int prev) {
    struct pq *PriorityQueue = newPQ();
    PriorityQueue = initPQ(PriorityQueue);


    dist[prev] = 0;
    while (PriorityQueue->count != 0) {
        for (allEdgeList) {
            if (next == allEdgeList[i] && 
                dist(prev) + weight(prev, next) < dist[next]) {
                    dist[next] = dist[prev] + weight(prev, next);
                    prev[next] = prev;
                    updatePQ(PriorityQueue, next, dist[next]);
            }
        }
    }


}

struct pq 
*initPQ(struct graph *g, struct pq *PriorityQueue) {
    PriorityQueue->queue = (int ***)malloc(sizeof(g->numVertices * (*(PriorityQueue->queue))));
    for(int i=0;i<g->numVertices;i++ ) {
        PriorityQueue->queue[i] = (int *)malloc(sizeof(int));
    }

    PriorityQueue->priorities = (int *)malloc(sizeof(g->numVertices * (*(PriorityQueue->priorities))));
    for(int j=0;j<g->numVertices;j++) {
        PriorityQueue->priorities[j] = INFINITY;
    }

    return PriorityQueue;
}


int
findDistance(struct graph *g, int start, int end) {
    // find edge in E
    for(int i=0; i<g->numEdges; i++) {
        // if can't find, return -1. if found, return distance
        if (g->edgeList[i]->start == start && 
            g->edgeList[i]->end == end) {
            return g->edgeList[i]->cost;
        } else { 
            return NULL;
        }
    }
}



// struct edge 
// **findAlledge(struct graph *g, int vertex) {
//     // create a edge list
//     struct edge **allEdge = NULL;
//     allEdge = (struct edge **) malloc(g->numEdges * sizeof(struct edge *));

//     // find all edge that start from vertex
//     int count = 0;
//     for(int i=0; i<g->numEdges; i++) {
//         if (g->edgeList[i]->start == vertex){
//             // add those edge into edge list
//             allEdge[count]->start = g->edgeList[i]->start;
//             allEdge[count]->end = g->edgeList[i]->end;
//             allEdge[count]->cost = g->edgeList[i]->cost;
//             count++;
//         }
//     }
//     return allEdge;
// }


// void
// updatePriorityQueue();

























// int
// findLowestCost(struct graph *g, int vertex) {
//     // create a edge list
//     struct edge **allEdge = NULL;
//     allEdge = (struct edge **) malloc(g->numEdges * sizeof(struct edge *));

//     // find all edge that start from vertex
//     int count = 0;
//     for(int i=0; i<g->numEdges; i++) {
//         if (g->edgeList[i]->start == vertex){
//             // add those edge into edge list
//             allEdge[count]->start = g->edgeList[i]->start;
//             allEdge[count]->end = g->edgeList[i]->end;
//             allEdge[count]->cost = g->edgeList[i]->cost;
//             count++;
//         }
//     }

//     // find lowest cost
//     int lowestElement = 0;
//     for(int i=0; i<count;i++) {
//         if(allEdge[i]->cost < allEdge[lowestElement]->cost) {
//             lowestElement = i;
//         }
//     }

//     return allEdge[lowestElement]->cost;
// }




