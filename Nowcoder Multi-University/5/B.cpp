/*
 * @Date         : 2020-07-25 23:17:04
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e6 + 5;
struct edge {
    int v, l;
};
vector<edge> g[maxn];
int n, tot, sz[maxn], ls[maxn], rs[maxn], rt, val[maxn];
ll ans, bin[35];

void get_val(int u, int fa)
{
    for (auto& v : g[u]) {
        if (v.v == fa) continue;
        val[v.v] = val[u] ^ v.l;
        get_val(v.v, u);
    }
}

void insert(int& x, int val, int d)
{
    if (!x) x = ++tot;
    if (d == -1) {
        sz[x] = 1;
        return;
    }
    if (bin[d] & val)
        insert(rs[x], val, d - 1);
    else
        insert(ls[x], val, d - 1);
    sz[x] = sz[rs[x]] + sz[ls[x]];
}

ll query(int x, int val, int d)
{
    if (d == -1) return 0;
    if (val & bin[d]) {
        if (rs[x]) return query(rs[x], val, d - 1);
        return query(ls[x], val, d - 1) + bin[d];
    }
    else {
        if (ls[x]) return query(ls[x], val, d - 1);
        return query(rs[x], val, d - 1) + bin[d];
    }
}

ll merge(int l, int r, int d, int val, int dd)
{
    if (d == -1) return query(r, val, dd);
    ll res = 1 << 30;
    if (ls[l]) res = min(res, merge(ls[l], r, d - 1, val, dd));
    if (rs[l]) res = min(res, merge(rs[l], r, d - 1, val + bin[d], dd));
    return res;
}

void dfs(int x, int d)
{
    if (d == -1) return;
    if (ls[x]) dfs(ls[x], d - 1);
    if (rs[x]) dfs(rs[x], d - 1);
    if (!ls[x] || !rs[x]) return;
    int l = ls[x], r = rs[x];
    if (sz[l] > sz[r]) swap(l, r);
    ans += merge(l, r, d - 1, 0, d - 1) + bin[d];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    bin[0] = 1;
    for (int i = 1; i < 32; i++) bin[i] = bin[i - 1] << 1;
    get_val(0, 0);
    for (int i = 0; i < n; i++) insert(rt, val[i], 30);
    dfs(rt, 30);
    cout << ans << endl;
}