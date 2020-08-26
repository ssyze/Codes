#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 7, INF = 0x3f3f3f3f;

const ll LNF = 0x3f3f3f3f3f3f3f3f;

struct E {
    int u, v, t;
} e[N];
int cnt;
#define lc ch[x][0]
#define rc ch[x][1]
struct LCT {
    int fa[N], ch[N][2], st[N];
    int mm[N], id[N], val[N];
    bool rev[N];
    inline bool nroot(int x)
    { //判断节点是否为一个Splay的根
        return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
    } //原理很简单，如果连的是轻边，他的父亲的儿子里没有它
    inline void pushup(int x)
    { //上传信息
        id[x] = x;
        mm[x] = val[x];
        if (lc && mm[x] > mm[lc]) {
            mm[x] = mm[lc];
            id[x] = id[lc];
        }
        if (rc && mm[x] > mm[rc]) {
            mm[x] = mm[rc];
            id[x] = id[rc];
        }
    }
    inline void pushr(int x)
    { //翻转操作,区间中有序的都要记得操作
        int t = lc;
        lc = rc;
        rc = t;
        rev[x] ^= 1;
    }

    inline void pushdown(int x)
    { //判断并释放懒标记
        if (rev[x]) {
            pushr(lc);
            pushr(rc);
            rev[x] = 0;
        }
    }
    inline void rotate(int x)
    { //一次旋转
        int y = fa[x], z = fa[y], k = ch[y][1] == x, w = ch[x][!k];
        if (nroot(y)) ch[z][ch[z][1] == y] = x;
        ch[x][!k] = y;
        ch[y][k] = w;
        if (w) fa[w] = y;
        fa[y] = x;
        fa[x] = z;
        pushup(y);
    }
    /*void pushall(int x){
          if(nroot(x))pushall(fa[x]);
          pushdown(x);
          }*/
    inline void splay(int x)
    {
        int y = x, z = 0;
        // pushall(x);
        st[++z] = y; // st为栈，暂存当前点到根的整条路径，pushdown时一定要从上往下放标记
        while (nroot(y)) st[++z] = y = fa[y];
        while (z) pushdown(st[z--]);
        while (nroot(x)) {
            y = fa[x];
            z = fa[y];
            if (nroot(y)) rotate((ch[y][0] == x) ^ (ch[z][0] == y) ? x : y);
            rotate(x);
        }
        pushup(x);
    }

    inline void access(int x)
    { //访问
        for (int y = 0; x; x = fa[y = x]) splay(x), rc = y, pushup(x);
    }
    inline void makeroot(int x)
    { //换根
        access(x);
        splay(x);
        pushr(x);
    }
    inline int findroot(int x)
    { //找根（在真实的树中的）
        access(x);
        splay(x);
        while (lc) pushdown(x), x = lc;
        splay(x);
        return x;
    }
    void split(int x, int y)
    { //提取路径
        makeroot(x);
        access(y);
        splay(y);
    }
    void link(int x, int y)
    { //连边
        makeroot(x);
        if (findroot(y) != x) fa[x] = y;
    }
    void cut(int x, int y)
    { //断边
        makeroot(x);
        if (findroot(y) == x && fa[y] == x && !ch[y][0]) {
            fa[y] = ch[x][1] = 0;
            pushup(x);
        }
    }
} lct;

const int M = 2e5 + 7;
vector<int> add[M], del[M];
map<pair<int, int>, int> mp;
int fan[2][M], fantot[2], ok[M], d[M], tot, n, m, q;
inline void addfan(int x, int k)
{
    if (fan[k][x] == 0) {
        ++fantot[k];
    }
    fan[k][x]++;
}
inline void delfan(int x, int k)
{
    fan[k][x]--;
    if (fan[k][x] == 0) {
        --fantot[k];
    }
}
int vis[N];
void addedge(int x)
{
    int u = e[x].u, v = e[x].v, t = e[x].t;
    if (lct.findroot(u) == lct.findroot(v)) {
        lct.split(u, v);
        if (e[x].t <= lct.mm[v]) return;
        int id = lct.id[v];
        lct.cut(e[id - n - m].u, id);
        lct.cut(e[id - n - m].v, id);
        vis[id - n - m] = 0;
        lct.link(u, x + n + m);
        lct.link(v, x + n + m);
        vis[x] = 1;
    }
    else {
        lct.link(u, x + n + m);
        lct.link(v, x + n + m);
        vis[x] = 1;
        --tot;
    }
}
void deledge(int x)
{
    if (!vis[x]) return;
    int u = e[x].u, v = e[x].v, t = e[x].t;
    lct.cut(u, x + n + m);
    lct.cut(v, x + n + m);
    vis[x] = 0;
    tot++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        int k, t;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            cin >> t;
            addfan(t, 0);
            addfan(i, 1);
            t += n;
            e[++cnt] = E { i, t, q + 1 };
            mp[make_pair(i, t)] = cnt;
            add[0].push_back(cnt);
        }
    }
    for (int x, y, i = 1; i <= q; ++i) {
        cin >> x >> y;
        int id = mp[make_pair(y, x + n)];
        if (!id) {
            addfan(x, 0);
            addfan(y, 1);
            d[i] = n - fantot[1];
            ok[i] = fantot[0] == m;
            e[++cnt] = E { y, x + n, q + 1 };
            mp[make_pair(y, x + n)] = cnt;
            add[i].push_back(cnt);
        }
        else {
            mp[make_pair(y, x + n)] = 0;
            delfan(x, 0);
            delfan(y, 1);
            d[i] = n - fantot[1];
            ok[i] = fantot[0] == m;
            e[id].t = i;
            del[i].push_back(id);
        }
    }
    for (int i = 1; i <= n + m; ++i) {
        lct.val[i] = INF;
        lct.pushup(i);
    }
    for (int i = 1; i <= cnt; ++i) {
        lct.val[i + n + m] = e[i].t;
        lct.pushup(i + n + m);
    }
    tot = n + m;
    for (int x : add[0]) {
        addedge(x);
    }
    for (int i = 1; i <= q; ++i) {
        for (int x : add[i]) addedge(x);
        for (int x : del[i]) deledge(x);
        if (ok[i])
            cout << tot - d[i] << '\n';
        else
            cout << "-1\n";
    }
}