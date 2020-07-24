/*
 * @Date         : 2020-03-04 16:28:00
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
bool vis[maxn];
int lowcost[maxn];
int N, M; //顶点数量,最小生成树权值
int graph[maxn][maxn];
int Prim(int node)
{
    memset(vis, 0, sizeof(vis)); //初始化vis数组
    vis[node] = true;
    for (int i = 1; i <= N; i++) //更新lowcost数组
        lowcost[i] = graph[node][i];
    int cnt = 1, ans = 0; //将起点加入点集合
    while (cnt != N) //当点集合数量不等于顶点数量时循环
    {
        int min1 = INF, pos; //设置最小值和其下标
        for (int i = 2; i <= N; i++) { //若该点没有加入点集合，且lowcost小于最小值
            if (!vis[i] && min1 > lowcost[i]) {
                min1 = lowcost[i]; //更新最小值
                pos = i; //更新下标
            }
        }
        vis[pos] = true; //将该点加入点集合
        ans += min1; //答案加上最小权值
        cnt++; //点集合数量+1
        for (int i = 1; i <= N; i++) //更新lowcost数组
        {
            lowcost[i] = min(lowcost[i], graph[pos][i]);
        }
    }
    return ans;
}
int main()
{
    while (cin >> N >> M) {
        memset(graph, INF, sizeof(graph));
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u][v] = w;
            graph[v][u] = w;
        }
        cout << Prim(1) << endl;
    }
}