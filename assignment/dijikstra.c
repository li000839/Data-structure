#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "graph.h"
#include "pq.h"

int
findCableTotal(struct graph *g, int startPoint) {
    struct pq *PriorityQueue = newPQ();

    
    return;
}

int
findAlledge() {
    
}

int
findDistance(struct graph *g, int startPoint, int endPoint) {
    // find edge in E
    for(int i=0; i<g->numEdges; i++) {
        // if can't find, return -1. if found, return distance
        if (g->edgeList[i]->start == startPoint && 
            g->edgeList[i]->end == endPoint) {
            return g->edgeList[i]->cost;
        } else { 
            return -1;
        }
    }
}

void
updatePriorityQueue() {

}
