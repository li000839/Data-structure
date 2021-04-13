#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "pq.h"

int
findCableTotal(struct graph *g, int startPoint) {
    struct pq *PriorityQueue = *newPQ();
    int **queue[总共有多少点][总共有多少点] = ;
    int bestPath[总共有多少点] = ;
    // 从起点开始

    // 优先序列是挑选下一个点的工具， 用优先序列挑选下一个点
        // 把所有点加入优先序列,直到queue的每一行都被移除/bestpath==总点数,每一轮
            // 记录上一个点（起点）
            // 插入优先序列
                // bestpath移除的不插入，剩下的都插，插入一行，一个点的所有相邻点
                // 根据上一个点，插入上一个点到所有相邻点的distance
                // 选一个最小的移出优先序列，记录到bestPath
    // 根据bestpath计算费用
}

int
findDistance(struct graph *g, int startPoint, int endPoint) {
    // find edge in E
    for(int i=0; i<g>-numEdges; i++) {
        if (g->edge[i]->start == startPoint && g->edge[i]->end == endPoint) {
            
        }
    }
    
    // if can't find, return NULL
    // if found, return distance
}