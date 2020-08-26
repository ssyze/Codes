/*
 * @Date         : 2020-08-17 19:48:05
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
#define lc ch[x][0]
#define rc ch[x][1]
const int maxn = 1e5 + 5;
int n, m, x, y, val[maxn];
struct LCT {
    int fa[maxn], ch[maxn][2], st[maxn], ans[maxn];
    bool rev[maxn];
    inline bool nroot(int x)
    { //判断节点是否为一个Splay的根
        return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
    } //原理很简单，如果连的是轻边，他的父亲的儿子里没有它
    inline void pushup(int x)
    { //上传信息
        ans[x] = ans[lc] ^ ans[rc] ^ val[x];
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
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1, op; i <= m; i++) {
        cin >> op >> x >> y;
        if (op == 0) {
            lct.split(x, y);
            cout << lct.ans[y] << '\n';
        }
        else if (op == 1)
            lct.link(x, y);
        else if (op == 2)
            lct.cut(x, y);
        else if (op == 3)
            lct.splay(x), val[x] = y;
    }
}