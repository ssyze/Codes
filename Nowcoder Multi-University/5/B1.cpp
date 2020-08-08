/*
 * @Date         : 2020-07-25 23:38:05
 * @Author       : ssyze
 * @Description  :
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define RG register
#define il inline
#define iter iterator
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
typedef long long ll;
const int N = 4000005;
vector<int> all;
struct Edge {
    int to, w;
};
vector<Edge> G[N];
void getval(int u, int val, int fa = -1)
{
    all.push_back(val);
    for (auto &e : G[u])
        if (e.to != fa) getval(e.to, val ^ e.w, u);
}
int n, rt = 0, bin[35], sz[N], ls[N], rs[N], totnode = 0;
ll ans = 0;

il void ins(int &x, int v, int d)
{
    if (!x) x = ++totnode;
    if (d == -1) {
        sz[x] = 1;
        return;
    }
    if (bin[d] & v)
        ins(rs[x], v, d - 1);
    else
        ins(ls[x], v, d - 1);
    sz[x] = sz[ls[x]] + sz[rs[x]];
}

il int qry(int x, int v, int d)
{
    cout << x << ' ' << v << ' ' << d << endl;
    if (d == -1) return 0;
    if (v & bin[d]) {
        if (rs[x]) return qry(rs[x], v, d - 1);
        return qry(ls[x], v, d - 1) + bin[d];
    }
    else {
        if (ls[x]) return qry(ls[x], v, d - 1);
        return qry(rs[x], v, d - 1) + bin[d];
    }
}

il int merge(int x, int y, int d, int val, int sd)
{
    cout << x << ' ' << y << ' ' << d << ' ' << val << ' ' << sd << endl;
    if (d == -1) return qry(y, val, sd);
    int ret = 1 << 30;
    if (ls[x]) ret = min(ret, merge(ls[x], y, d - 1, val, sd));
    if (rs[x]) ret = min(ret, merge(rs[x], y, d - 1, val + bin[d], sd));
    cout << ret << "*" << endl;
    return ret;
}

il void dfs(int x, int d)
{
    if (d == -1) return;
    if (ls[x]) dfs(ls[x], d - 1);
    if (rs[x]) dfs(rs[x], d - 1);
    if (!ls[x] || !rs[x]) return;
    int l = ls[x], r = rs[x];
    if (sz[l] > sz[r]) swap(l, r);
    ans += merge(l, r, d - 1, 0, d - 1) + bin[d];
    cout << ans << endl;
}

void work()
{
    int n;
    cin >> n;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        G[u].push_back(Edge{v, w});
        G[v].push_back(Edge{u, w});
    }
    getval(0, 0);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto u : all) ins(rt, u, 31);
    dfs(rt, 31);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bin[0] = 1;
    for (int i = 1; i <= 31; i++) bin[i] = bin[i - 1] << 1;
    work();
    return 0;
}