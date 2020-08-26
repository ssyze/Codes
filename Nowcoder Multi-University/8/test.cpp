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

int main()
{
    lct.id[1] = 1, lct.id[2] = 2, lct.id[3] = 3;
    lct.val[1] = 3, lct.val[2] = 3, lct.val[3] = 1;
    lct.link(1, 3), lct.link(2, 3);
    lct.split(1, 2);
    cout << lct.id[2] << endl;
}