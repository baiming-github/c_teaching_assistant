/* 
 [Shortest path problem 1] I
mplementation of Dijkstra algorithm to solve the shortest path
 problem based on the techniques of dynamic memory allocation and
 recursion
 ［最短路問題 1］
 グラフ理論における基本的な問題の1つである最短路問題は、鉄道の乗り換え検索やカーナ
 ビゲーション等にも応用されている。この最短路問題を解く代表的アルゴリズムであるダイ
 クストラ法をC言語を用いて実装する。
 Dijkstra(迪杰斯特拉)算法是典型的最短路径路由算法，用于计算一个节点到其他所有节点的最短路径。主要特点是以起始点为中心向外层层扩展，直到扩展到终点为止。Dijkstra算法能得出最短路径的最优解，但由于它遍历计算的节点很多，所以效率低。
 */

#include <stodio.h>

#define INF 1000000000
int n;//n は頂点数
int dist[100][100];//x->y の辺があるところにその長さ入れておく、もしないところに無限を入れて（無限に変わってINF）
int cost[100];
char used[100];
//関数diを実行すると、cost[x]に目的地g(変化しつつ)までの最短距離が入ります
//xから目的地までgまでいけないときは無限のままになります
void di(int g){
    
    
    int x,y,min;
    for (x = 0; x < n; x++) {
        cost[x] = INF;//全ての点を「未使用」にしておく(無限の値)
        used[x] = 0;//目的地gのコスト（目的地までの最短距離を覚えておく）をゼロに初期化
    }
    cost[g] = 0;//g点から始める
    while (1) {
        min = INF;
        for (x=0; x<n ; x++) {
            if (!used[x]&& min > cost[x]) {
                min = cost[x];
            }
            if (min == INF) {
                break;
            }
            for (y=0; y<n; y++) {
                if (cost[y]==min) {
                    for (x=0; x<n; x++) {
                        if (cost[x]>dist[x][y]+cost[y]) {
                            cost[x]= dist[x][y]+cost[y];
                        }
                    }
                }
            }
        }
    }
}


//version2
const int  MAXINT = 32767;
const int MAXNUM = 10;
int dist[MAXNUM];
int prev[MAXNUM];

int A[MAXUNM][MAXNUM];

void Dijkstra(int v0)
{
    bool S[MAXNUM];                                  // 判断是否已存入该点到S集合中
    int n=MAXNUM;
    for(int i=1; i<=n; ++i)
    {
        dist[i] = A[v0][i];
        S[i] = false;                                // 初始都未用过该点
        if(dist[i] == MAXINT)
            prev[i] = -1;
        else
            prev[i] = v0;
    }
    dist[v0] = 0;
    S[v0] = true;
    for(int i=2; i<=n; i++)
    {
        int mindist = MAXINT;
        int u = v0;                              // 找出当前未使用的点j的dist[j]最小值
        for(int j=1; j<=n; ++j)
            if((!S[j]) && dist[j]<mindist)
            {
                u = j;                            // u保存当前邻接点中距离最小的点的号码
                mindist = dist[j];
            }
        S[u] = true;
        for(int j=1; j<=n; j++)
            if((!S[j]) && A[u][j]<MAXINT)
            {
                if(dist[u] + A[u][j] < dist[j])    //在通过新加入的u点路径找到离v0点更短的路径
                {
                    dist[j] = dist[u] + A[u][j];    //更新dist
                    prev[j] = u;                    //记录前驱顶点
                }
            }
    }
}