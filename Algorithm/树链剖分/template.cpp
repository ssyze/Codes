#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int fa[maxn], dep[maxn], maxson[maxn], son[maxn], siz[maxn]; // dfs数组
int top[maxn], dfn[maxn], tot, has[maxn]; // link数组
int a[maxn], Sum[maxn << 2], lazy[maxn << 2];
int head[maxn], cnt, val[maxn];
struct e {
    int to, nxt;
} edge[maxn];
int n, m, r, mod;
void addedge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
int dfs(int u)
{
    int ret = 0;
    siz[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        int sz = dfs(v);
        siz[u] += siz[v];
        ret += sz;
        if (sz > maxson[u]) {
            maxson[u] = sz;
            son[u] = v;
        }
    }
    return ret + 1;
}
void link(int u, int t)
{
    dfn[u] = ++tot;
    has[tot] = u;
    top[u] = t;
    if (son[u]) link(son[u], t);
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == fa[u] || v == son[u]) continue;
        link(v, v);
    }
}
void hld()
{
    dfs(r);
    link(r, r);
}

//更新当前节点
void pushup(int& rt, int l, int r) { rt = l + r; }
//下传函数
void pushdown(int l, int r, int rt)
{
    //区间改值
    /* if (lazy[rt]) {
        int m = (l + r) >> 1;
        lazy[rt << 1] = lazy[rt];
        lazy[rt << 1 | 1] = lazy[rt];
        Sum[rt << 1] = lazy[rt] * (m - l + 1);
        Sum[rt << 1 | 1] = lazy[rt] * (r - m);
        lazy[rt] = 0;
    } */
    //区间增减
    if (lazy[rt]) {
        int m = (l + r) >> 1;
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        Sum[rt << 1] += lazy[rt] * (m - l + 1);
        Sum[rt << 1 | 1] += lazy[rt] * (r - m);
        Sum[rt << 1] %= mod;
        Sum[rt << 1 | 1] %= mod;
        lazy[rt] = 0;
    }
}
// l:当前节点的左端点 r：当前节点的右端点 rt:当前节点的编号
void build(int l, int r, int rt)
{
    if (l == r) {
        Sum[rt] = val[has[l]];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushup(Sum[rt], Sum[rt << 1], Sum[rt << 1 | 1]);
}
// l:当前节点的左端点 r：当前节点的右端点 rt:当前节点的编号 [L,R]查询的区间
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r) return Sum[rt];
    int m = (l + r) >> 1;
    pushdown(l, r, rt);
    if (R <= m)
        return query(L, R, l, m, rt << 1) % mod;
    else if (L >= m + 1)
        return query(L, R, m + 1, r, rt << 1 | 1) % mod;
    else {
        int res = 0;
        pushup(res, query(L, R, l, m, rt << 1), query(L, R, m + 1, r, rt << 1 | 1));
        return res % mod;
    }
}
// l:当前节点的左端点 r：当前节点的右端点 rt:当前节点的编号 将L的值改为V
void update(int L, int V, int l, int r, int rt)
{
    if (l == r) {
        Sum[rt] = V;
        return;
    }
    int m = (l + r) >> 1;
    pushdown(l, r, rt);
    if (L <= m)
        update(L, V, l, m, rt << 1);
    else
        update(L, V, m + 1, r, rt << 1 | 1);
    pushup(Sum[rt], Sum[rt << 1], Sum[rt << 1 | 1]);
}
void segupdate(int L, int R, int l, int r, int rt, int lzy)
{
    if (L <= l && R >= r) {
        //区间改值
        /* lazy[rt] = lzy;
        Sum[rt] = (r - l + 1) * lzy; */
        //区间加减
        lazy[rt] += lzy;
        Sum[rt] += (r - l + 1) * lzy;
        Sum[rt] %= mod;
        return;
    }
    int m = (l + r) >> 1;
    pushdown(l, r, rt);
    if (L <= m) segupdate(L, R, l, m, rt << 1, lzy);
    if (R > m) segupdate(L, R, m + 1, r, rt << 1 | 1, lzy);
    pushup(Sum[rt], Sum[rt << 1], Sum[rt << 1 | 1]);
    return;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    memset(head, -1, sizeof(head));
    cin >> n >> m >> r >> mod;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }
    hld();
    build(1, n, 1);
    for (int i = 1, op, x, y, z; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            z %= mod;
            int l, r;
            while (top[x] != top[y]) {
                if (dep[top[x]] < dep[top[y]]) swap(x, y);
                l = dfn[top[x]], r = dfn[x];
                segupdate(l, r, 1, n, 1, z);
                x = fa[top[x]];
            }
            if (dfn[x] > dfn[y]) swap(x, y);
            segupdate(dfn[x], dfn[y], 1, n, 1, z);
        }
        else if (op == 2) {
            cin >> x >> y;
            int ans = 0, l, r;
            while (top[x] != top[y]) {
                if (dep[top[x]] < dep[top[y]]) swap(x, y);
                l = dfn[top[x]], r = dfn[x];
                ans = (ans + query(l, r, 1, n, 1)) % mod;
                x = fa[top[x]];
            }
            if (dfn[x] > dfn[y]) swap(x, y);
            ans = (ans + query(dfn[x], dfn[y], 1, n, 1)) % mod;
            cout << ans << '\n';
        }
        else if (op == 3) {
            cin >> x >> z;
            z %= mod;
            // cout << dfn[x] << ' ' << dfn[x] + maxson[x] << '\n';
            segupdate(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1, z);
        }
        else if (op == 4) {
            cin >> x;
            cout << query(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1) % mod << '\n';
        }
    }
}