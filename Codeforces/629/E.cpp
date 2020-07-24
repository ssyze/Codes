/*
 * @Date         : 2020-03-31 13:16:25
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 200;
int n, m, weight[maxn], Size[maxn], sum[maxn];
int dep[maxn], cnt;
vector<int> E[maxn];
int parent[maxn], son[maxn], top[maxn], rk[maxn];

void dfs1(int u, int fa, int root)
{
    parent[u] = fa;
    dep[u] = dep[fa] + 1;
    Size[u] = 1;
    for (int v, i = 0; i < E[u].size(); ++i) {
        if ((v = E[u][i]) != fa) {
            dfs1(v, u, root);
            Size[u] += Size[v];
            if (Size[v] > Size[son[u]])
                son[u] = v;
        }
    }
}

int dfs2(int u, int t)
{
    top[u] = t;
    rk[u] = ++cnt;
    sum[rk[u]] = weight[u];
    if (son[u] != 0)
        dfs2(son[u], t);
    for (int v, i = 0; i < E[u].size(); ++i)
        if ((v = E[u][i]) != son[u] && v != parent[u])
            dfs2(v, v);
}

int LCA(int a, int b)
{
    while (top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]])
            swap(a, b);
        a = parent[top[a]];
    }
    if (dep[a] < dep[b])
        swap(a, b);
    return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    while (m--) {
        int cnt;
        cin >> cnt;
        vector<int> v(cnt);
        for (int i = 0; i < cnt; i++)
            cin >> v[i];
        sort(v.begin(), v.end(), [&](int u, int v) { return dep[u] > dep[v]; });
        bool flag = 1;
        for (int i = 1; i < cnt; i++) {
            if (dep[v[i]] - dep[LCA(v[i], v[0])] > 1) {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}