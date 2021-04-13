#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "graph.h"
#include "pq.h"

int
findCableTotal(struct graph *g, int startPoint) {
    struct pq *PriorityQueue = newPQ();
    int **queue = initializeMaxtrix(g, g->numVertices);
    int *bestPath = initializeArray(g->numVertices);

    // 从起点开始 

    // 优先序列是挑选下一个点的工具， 用优先序列挑选下一个点
        // 把所有点加入优先序列,直到queue的每一行都被移除/bestpath==总点数,每一轮
        while(*bestPath[(g->numVertices)-1] == -1){
            // 记录上一个点（起点）
            int prePoint = startPoint;
            // 插入优先序列
                // bestpath移除的不插入，剩下的都插，插入一行，一个点的所有相邻点
                
                // 根据上一个点，插入上一个点到所有相邻点的distance
                // 选一个最小的移出优先序列，记录到bestPath
        }
            
    // 根据bestpath计算费用
    return;
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

int
*initializeArray(int num) {
    int array[num];
    for(int i=0;i<num;i++) {
        array[i] = -1;
    }
    return array;
}

int
initializeMaxtrix(struct graph *g, int num) {
    int row = num;
    int col = num;
    int **queue[row][col];

    for(int rowElement=0;rowElement<row;rowElement++) {
        for(int colElement=0;colElement<col;colElement++) {
            for(int edge=0;edge<g->numEdges;edge++) {
                if (g->edgeList[edge]->start == rowElement &&
                    g->edgeList[i]->end == colElement){
                    **queue[rowElement][colElement] = 1;
                } else {
                    **queue[rowElement][colElement] = 0;
                }
            }
        }
    }
    return queue;
}