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

void
dijkstra(struct graph *g, int start) {
    // initialize pq
    struct pq *PriorityQueue = newPQ();
    PriorityQueue = initPQ(g, PriorityQueue, start);
    
    struct path *finalPath = NULL;
    finalPath = (struct path *)malloc(sizeof(struct path));
    while (PriorityQueue->count != 0) {
        // eject min
        struct path * item = NULL;
        item = deletemin(PriorityQueue);
        int i = g->numVertices - PriorityQueue->count;
        addFinalPath(finalPath, item, i);
        
        // get all possible edge from prev
        int prev = item->vertex;
        int totalDistanceToPerv = 0;
        for (int i=0;i<g->numEdges;i++) {
            if (g->edgeList[i]->start == prev) {
                int cur = g->edgeList[i]->end;
                // check whether cur inside pq
                for (int j=0;j<PriorityQueue->count;j++) {
                    int distPrevToNext = findDistance(g, prev, cur);
                    if (cur == PriorityQueue->queue[j]->vertex &&
                        totalDistanceToPerv + distPrevToNext < 
                        PriorityQueue->priorities[j]) {
                            PriorityQueue->priorities[j] = totalDistanceToPerv + distPrevToNext;
                    }
                }
            }




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
*initPQ(struct graph *g, struct pq *PriorityQueue, int start) {
    struct path *item = NULL;
    item = (struct path *)malloc(sizeof(struct path));
    
    for(int i=0;i<g->numVertices;i++) {
        if(i == start) {
            enqueue(PriorityQueue, item, 0);
        } else {
            enqueue(PriorityQueue, item, INFINITY);
        } 
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

void
addFinalPath(int *finalPath, struct path *item, int count) {
    finalPath[count] = item;
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




