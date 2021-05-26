#include <stdio.h>
#include <assert.h>
#include "graph.h"

void printnum(char *string, int num) {
    printf("%s is %d\n", string, num);
}

void printorder(int *order, int n) {
    for(int i = 0; i < n; i++) {
        printf("No.%d is %d\n", i, order[i]);
        i++;
    }
}

void printedgeList(struct graph *g){
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d %d\n", g->edgeList->start, g->edgeList->end);
    }
}