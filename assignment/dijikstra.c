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
    int totalDistanceToPerv = 0;
    while (PriorityQueue->count != 0) {
        // eject min
        struct path * item = NULL;
        item = deletemin(PriorityQueue);
        int i = g->numVertices - PriorityQueue->count;
        addFinalPath(finalPath, item, i);
        
        // get all possible edge from prev
        int prev = item->vertex;
        for (int prevIndex=0;prevIndex<g->numEdges;prevIndex++) {
            if (g->edgeList[prevIndex]->start == prev) {
                int cur = g->edgeList[prevIndex]->end;
                // check whether cur inside pq
                for (int curIndex=0;curIndex<PriorityQueue->count;curIndex++) {
                    int distPrevToCur = findDistance(g, prev, cur);
                    int priority = PriorityQueue->priorities[cur];
                    if (cur == PriorityQueue->queue[curIndex]->vertex &&
                        totalDistanceToPerv + distPrevToCur < priority) {
                            priority = totalDistanceToPerv + distPrevToCur;
                            prev = cur;
                            update(PriorityQueue, cur, priority);
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


void
update(struct pq *PriorityQueue, int cur, int priority) {
    // record total path

    // record total priority

}

























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




