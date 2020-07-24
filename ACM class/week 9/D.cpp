#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int dfn[maxn], low[maxn], scc[maxn];
bool vis[maxn];
int idx;
int sccnum, n, m;
vector<int> edge[maxn];
stack<int> s;
void tarjan(int x)
{
    vis[x] = 1;
    dfn[x] = low[x] = ++idx;
    s.push(x);
    for (int i = 0; i < edge[x].size(); i++) {
        int s = edge[x][i];
        if (!vis[s]) {
            tarjan(s);
            low[x] = min(low[x], low[s]);
        }
        else if (!scc[s])
            low[x] = min(low[x], dfn[s]);
    }
    if (low[x] == dfn[x]) {
        ++sccnum;
        int num = 0;
        while (1) {
            int temp = s.top();
            s.pop();
            scc[temp] = sccnum;
            num++;
            if (temp == x) {
                if (num == 1)
                    --sccnum;
                break;
            }
        }
    }
}
int main()
{
    while (cin >> n >> m && (n + m)) {
        for (int i = 1; i <= n; i++)
            edge[i].clear();
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(scc, 0, sizeof(scc));
        memset(vis, 0, sizeof(vis));
        while (!s.empty())
            s.pop();
        sccnum = 0;
        idx = 0;
        int x1, x2;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &x1, &x2);
            edge[x1].push_back(x2);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i])
                tarjan(i);
        }
        cout << sccnum << endl;
    }
}