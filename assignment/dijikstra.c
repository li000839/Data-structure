#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "dijikstra.h"
#include "graph.h"
#include "pq.h"

int
findCableTotal(struct graph *g, int start) {
    
    dijkstra(g, start);

    calculateCost(PriorityQueue);
    
    return;
}

dijkstra(struct graph *g, int prev) {
    struct pq *PriorityQueue = newPQ();
    PriorityQueue = initPQ(g);


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

// int
// findDistance(int start) {
//     struct graph *g;
//     // find edge in E
//     for(int i=0; i<g->numEdges; i++) {
//         // if can't find, return -1. if found, return distance
//         if (g->edgeList[i]->start == startPoint && 
//             g->edgeList[i]->end == endPoint) {
//             return g->edgeList[i]->cost;
//         } else { 
//             return -1;
//         }
//     }
// }

// struct pq 
// *initPQ(struct graph *g) {
//     struct pq *PriorityQueue = newPQ();
//     struct edge *allEdge = NULL;
//     for(int i=0;i<g->numVertices;i++){
//         enqueue(PriorityQueue, findAlledge(g, i), findLowestCost(g, i));
//     }
//     return PriorityQueue;
// }

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




