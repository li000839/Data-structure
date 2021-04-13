#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "dijikstra.h"
#include "graph.h"
#include "pq.h"

int
findCableTotal(struct graph *g, int start) {
    
    int pre = start;
    return;
}

struct pq 
*initPQ(struct graph *g) {
    struct pq *PriorityQueue = newPQ();
    struct edge *allEdge = NULL;
    for(int i=0;i<g->numVertices;i++){
        enqueue(PriorityQueue, findAlledge(g, i), findLowestCost(g, i));
    }
    return PriorityQueue;
}

struct edge 
**findAlledge(struct graph *g, int vertex) {
    // create a edge list
    struct edge **allEdge = NULL;
    allEdge = (struct edge **) malloc(g->numEdges * sizeof(struct edge *));

    // find all edge that start from vertex
    int count = 0;
    for(int i=0; i<g->numEdges; i++) {
        if (g->edgeList[i]->start == vertex){
            // add those edge into edge list
            allEdge[count]->start = g->edgeList[i]->start;
            allEdge[count]->end = g->edgeList[i]->end;
            allEdge[count]->cost = g->edgeList[i]->cost;
            count++;
        }
    }
    return allEdge;
}

int
findLowestCost(struct graph *g, int vertex) {
    // create a edge list
    struct edge **allEdge = NULL;
    allEdge = (struct edge **) malloc(g->numEdges * sizeof(struct edge *));

    // find all edge that start from vertex
    int count = 0;
    for(int i=0; i<g->numEdges; i++) {
        if (g->edgeList[i]->start == vertex){
            // add those edge into edge list
            allEdge[count]->start = g->edgeList[i]->start;
            allEdge[count]->end = g->edgeList[i]->end;
            allEdge[count]->cost = g->edgeList[i]->cost;
            count++;
        }
    }

    // find lowest cost
    int lowestElement = 0;
    for(int i=0; i<count;i++) {
        if(allEdge[i]->cost < allEdge[lowestElement]->cost) {
            lowestElement = i;
        }
    }

    return allEdge[lowestElement]->cost;
}


// int
// findDistance(struct graph *g, int startPoint, int endPoint) {
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

// void
// updatePriorityQueue();
