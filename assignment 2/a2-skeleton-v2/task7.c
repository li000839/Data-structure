// done of practicing with tarjan, running out of time to fit into assignment 2
// at least I did what I could do

#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

#define MAXN 1000  // maximum number of vertex

int n, m;  // n: number of vertexes, m: number of edges
int num[MAXN], low[MAXN], inde, res;
// num：记录每个点的时间戳
// low：能不经过父亲到达最小的编号，inde：时间戳，res：答案数量
bool vis[MAXN], flag[MAXN];  // flag: 答案 vis：标记是否重复
int edge[MAXN][MAXN];

int min(int a, int b) { return a < b ? a : b; }

void Tarjan(int u, int father) {  // u:id of current node，and father of u
    vis[u] = true;                // visit flag
    low[u] = num[u] = ++inde;
    int child = 0;
    int i, v;

    for (i = 0; i < n; i++) {  // traverse all neighbors of u
        if (!edge[u][i]) continue;
        v = i;

        if (!vis[v]) {
            child++;
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (father != u && low[v] >= num[u] && !flag[u]) {
                flag[u] = true;
                res++;
            }
        } else if (v != father)
            low[u] = min(low[u], num[v]);
    }
    if (father == u && child >= 2 && !flag[u]) {
        flag[u] = true;
        res++;
    }
}

// ./task7.exe network-1.txt < outage-1.txt
int main(int argc, char *argv[]) {

    freopen(argv[1],"r",stdin);

    scanf("%d%d", &n, &m);
    memset(edge, 0, sizeof(edge));

    int i;
    for (i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[x][y] = 1;
        edge[y][x] = 1;
    }

    for (int i = 0; i < n; i++)  // Tarjan 图不一定连通
        if (!vis[i]) {
            inde = 0;      
            Tarjan(i, i);        // 从第 i 个点开始，父亲为自己
        }

    // Output
    printf("The critical servers are:");
    for (int i = 0; i < n; i++)
        if (flag[i]) printf(" %d", i); 
    return 0;
}