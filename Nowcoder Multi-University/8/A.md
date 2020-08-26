2020Multi-University Nowcoder Day8

A. All-Star Game

# 题意:

有$n$个球员和$m$个球迷，一个球员可以有多个球迷，一个球迷也可以喜欢多个球员，同时关系是具有传递性的

现在要打全明星赛，求最少选多少个球员可以使每个球迷都来观看（只要有一个喜欢的球员入选就满足要求

同时还有$q$个关系的修改，对于$a_{i}$球员和$b_{j}$球迷，若原先$b_{j}$是$a_{i}$的球迷，修改后就不是了，若原先不是，则修改后是

每次修改后输出结果

数据范围：$1\le n,m,q \le 2 \times 10^5$ 

# 题解：

我们可以把这个问题先建个图来分析，对样例建图（输入需要处理一下

```
4 4 6
2 1 2
0
2 2 3
1 4
```

![image.png](https://i.loli.net/2020/08/19/3tcEfNiw5pa4MAI.png)

建完图是这个样子的，由于关系具有传递性，所以答案显然是$2$，选$1,4$或者$3,4$都是满足要求的

那么又可以发现，每一个连通块里选出一个球员就可以了，于是问题就转化成了求连通块数量的问题

最后$ans=$连通块数量$-$孤立球员数量，若存在孤立球迷，那么$ans=-1$

那么我们要做的就是在加边和删边的时候维护连通分量个数

加边的时候若$b_{i}$有边，则$ans-1$

删边的时候若$b_{i}$右边，则$ans+1$

因为加减边是确定的，所以可以把所有边先读进来离线做，做法有两种

①线段树+可撤销并查集 (~~我不会~~

②LCT (~~刚学会~~

用LCT做的话其实就是维护一棵删边时间最晚的生成树，但是我们在加边的时候可能会使这个连通块里出现环，所以我们要尽可能地让删除时间晚的边留在生成树里，这样子就能提供更好(？)的连通性

前两天之后相信大家都会LCT了（可能

为了用LCT解决这个问题，我们首先要确定每条边被删除的时间，代码是这个样子的（代码部分参考了罗老师队的代码

```cpp
    for (int i = 1, num; i <= n; i++) { // 处理初始输入， 0代表球员， 1代表球迷
        cin >> num;
        for (int j = 1, fan; j <= num; j++) {
            cin >> fan;		
            ad(i, 0);
            ad(fan, 1);
            e[++cnt] = { i, fan + n, q + 1 };	// 第i条边的信息，u, v, time
            lnk[{ i, fan }] = cnt;
            add[0].push_back(cnt);
        }
    }
    for (int i = 1, fan, player; i <= q; i++) {
        cin >> fan >> player;
        int r = lnk[{ player, fan }];	// 确定是否存在连接这两个人的边
        if (!r) {	// 若不存在， 加边
            ad(player, 0);
            ad(fan, 1);
            e[++cnt] = { player, fan + n, q + 1 }; // 加边
            lnk[{ player, fan }] = cnt;
            add[i].push_back(cnt); // 第i次询问加这条边
            ok[i] = tot[1] == m; // 有球迷孤立则无解
            p[i] = n - tot[0]; // 孤立球员的数量
        }
        else {	// 若存在， 删边
            de(player, 0);
            de(fan, 1);
            ok[i] = tot[1] == m;
            p[i] = n - tot[0];
            lnk[{ player, fan }] = 0;
            e[r].time = i; // 记录边删除的时间
            del[i].push_back(r); // 第i次询问删这条边
        }
    }
```

这个时候问题就来了，我们记录得到了每条边被删除的时间，可是在LCT里一般维护的都是点，维护边权需要做些额外的操作

![image.png](https://i.loli.net/2020/08/19/CWtRbQ8flpqdkoB.png)

比如这个样子的两个点，如果我们要维护边权可以这样处理

![image.png](https://i.loli.net/2020/08/19/HBZULcJTnqF5yPQ.png)

把边权化成点权处理，这样子要处理边权的时候就和处理点权的时候差不多了，只不过要注意

原来是`link(a,b)`现在需要`link(a,c),link(b,c)`需要把两个点都连在权值点上，cut的时候同理

最后就需要在LCT里收集信息了，我们需要收集是哪一条边最早删除，因此LCT里需要 $t_{i}$ 和 $id_{i}$ ，$t$是删除时间，$id$是边的序号

```cpp
inline void pushup(int x) // 这是LCT里的函数
{ //上传信息，生成树中最早删除的边，在根记录最早删除的时间和节点
    id[x] = x;
    t[x] = val[x];
    if (rc && t[x] > t[rc]) id[x] = id[rc], t[x] = t[rc];
    if (lc && t[x] > t[lc]) id[x] = id[lc], t[x] = t[lc];
}
//  这是加边删边的函数
void addedge(int x)
{
    int u = e[x].u, v = e[x].v, t = e[x].time;
    if (lct.findroot(u) == lct.findroot(v)) { // 在同一连通块内
        lct.split(u, v);
        if (t <= lct.t[v]) return; // 加的这条边是最早删除的就不加
        int id = lct.id[v]; // 提取最早删除的边的id
        lct.cut(e[id - n - m].u, id);
        lct.cut(e[id - n - m].v, id);
        vis[id - n - m] = 0;
        lct.link(u, x + n + m);
        lct.link(v, x + n + m);
        vis[x] = 1;
    }
    else { // 不在同一连通块内
        lct.link(u, x + n + m);
        lct.link(v, x + n + m);
        vis[x] = 1;
        sum--;
    }
}
void deledge(int x)
{
    if (!vis[x]) return;
    int u = e[x].u, v = e[x].v, t = e[x].time;
    lct.cut(u, x + n + m);
    lct.cut(v, x + n + m);
    sum++;
    vis[x] = 0;
}
```

完整代码如下

```cpp
/*
 * @Date         : 2020-08-18 23:26:46
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lc ch[x][0]
#define rc ch[x][1]
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e6 + 5;
struct edge {
    int u, v, time;
} e[maxn];
map<pair<int, int>, int> lnk;
vector<int> add[maxn], del[maxn], ans, ok(maxn), p(maxn);
int cnt, tot[2], pf[maxn][2], vis[maxn], sum;
// pf[i][0]表示球员，pf[i][1]表示球迷
// tot[0]表示连边的球员数量，tot[1]表示连边的球迷数量
struct LCT {
    int fa[maxn], ch[maxn][2], st[maxn], ans[maxn];
    int t[maxn], id[maxn], val[maxn];
    bool rev[maxn];
    inline bool nroot(int x)
    { //判断节点是否为一个Splay的根
        return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
    } //原理很简单，如果连的是轻边，他的父亲的儿子里没有它
    inline void pushup(int x)
    { //上传信息，生成树中最早删除的边，在根记录最早删除的时间和节点
        id[x] = x;
        t[x] = val[x];
        if (rc && t[x] > t[rc]) id[x] = id[rc], t[x] = t[rc];
        if (lc && t[x] > t[lc]) id[x] = id[lc], t[x] = t[lc];
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
int n, m, q;
// 0是球员， 1是球迷
void ad(int id, int _pf)
{
    if (!pf[id][_pf]) tot[_pf]++;
    pf[id][_pf]++;
}
void de(int id, int _pf)
{
    pf[id][_pf]--;
    if (!pf[id][_pf]) tot[_pf]--;
}
void addedge(int x)
{
    int u = e[x].u, v = e[x].v, t = e[x].time;
    if (lct.findroot(u) == lct.findroot(v)) { // 在同一连通块内
        lct.split(u, v);
        if (t <= lct.t[v]) return; // 加的这条边是最早删除的就不加
        int id = lct.id[v]; // 提取最早删除的边的id
        lct.cut(e[id - n - m].u, id);
        lct.cut(e[id - n - m].v, id);
        vis[id - n - m] = 0;
        lct.link(u, x + n + m);
        lct.link(v, x + n + m);
        vis[x] = 1;
    }
    else { // 不在同一连通块内
        lct.link(u, x + n + m);
        lct.link(v, x + n + m);
        vis[x] = 1;
        sum--;
    }
}
void deledge(int x)
{
    if (!vis[x]) return;
    int u = e[x].u, v = e[x].v, t = e[x].time;
    lct.cut(u, x + n + m);
    lct.cut(v, x + n + m);
    sum++;
    vis[x] = 0;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1, num; i <= n; i++) {
        cin >> num;
        for (int j = 1, fan; j <= num; j++) {
            cin >> fan;
            ad(i, 0);
            ad(fan, 1);
            e[++cnt] = { i, fan + n, q + 1 };
            lnk[{ i, fan }] = cnt;
            add[0].push_back(cnt);
        }
    }
    for (int i = 1, fan, player; i <= q; i++) {
        cin >> fan >> player;
        int r = lnk[{ player, fan }];
        if (!r) {
            ad(player, 0);
            ad(fan, 1);
            e[++cnt] = { player, fan + n, q + 1 }; // 边删除的时间
            lnk[{ player, fan }] = cnt;
            add[i].push_back(cnt);
            ok[i] = tot[1] == m; // 有球迷孤立则无解
            p[i] = n - tot[0]; // 孤立球员的数量
        }
        else {
            de(player, 0);
            de(fan, 1);
            ok[i] = tot[1] == m;
            p[i] = n - tot[0];
            lnk[{ player, fan }] = 0;
            e[r].time = i; // 记录边删除的时间
            del[i].push_back(r);
        }
    }
    for (int i = 1; i <= n + m; i++) lct.val[i] = inf;
    // 拆边，用点权维护边权
    for (int i = 1; i <= cnt; i++) lct.val[i + m + n] = e[i].time;
    sum = n + m;
    for (auto& x : add[0]) addedge(x);
    for (int i = 1; i <= q; i++) {
        for (auto& x : add[i]) addedge(x);
        for (auto& x : del[i]) deledge(x);
        if (ok[i])
            ans.push_back(sum - p[i]);
        else
            ans.push_back(-1);
    }
    for (auto& x : ans) cout << x << '\n';
}
```

