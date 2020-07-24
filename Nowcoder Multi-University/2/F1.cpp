/*
 * @Date         : 2020-07-13 14:31:05
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
#define N 5005
int D, S, q;
struct xds {  //内层（标记永久化）
#define Z int m = (l + r) >> 1
#define ls rt << 1
#define rs rt << 1 | 1
    int s[N * 4], tag[N * 4];
    void build(int l, int r, int rt)
    {  //内层建树
        if (l == r) {
            s[rt] = gi();
            return;
        }
        Z;
        build(l, m, ls);
        build(m + 1, r, rs);
        s[rt] = s[ls] + s[rs];
    }
    void upd(int L, int R, int v, int l, int r, int rt)
    {  //内层修改
        s[rt] += v * (R - L + 1);
        if (L == l && r == R) {
            tag[rt] += v;
            return;
        }
        Z;
        if (R <= m)
            upd(L, R, v, l, m, ls);
        else {
            if (L > m)
                upd(L, R, v, m + 1, r, rs);
            else
                upd(L, m, v, l, m, ls), upd(m + 1, R, v, m + 1, r, rs);
        }
    }
    int qh(int L, int R, int l, int r, int rt, int ad)
    {
        if (L == l && r == R) return s[rt] + ad * (r - l + 1);
        Z;
        ad += tag[rt];
        if (R <= m)
            return qh(L, R, l, m, ls, ad);
        else {
            if (L > m)
                return qh(L, R, m + 1, r, rs, ad);
            else
                return qh(L, m, l, m, ls, ad) + qh(m + 1, R, m + 1, r, rs, ad);
        }
    }
} s[N * 4], tag[N * 4];
void mg(xds& o, xds& lc, xds& rc, int l, int r, int rt)
{  //外层节点更新(pushup)
    o.s[rt] = lc.s[rt] + rc.s[rt];
    if (l == r) return;
    Z;
    mg(o, lc, rc, l, m, ls);
    mg(o, lc, rc, m + 1, r, rs);
}
void build(int l, int r, int rt)
{  //外层建树
    if (l == r) {
        s[rt].build(1, S, 1);
        return;
    }
    Z;
    build(l, m, ls);
    build(m + 1, r, rs);
    mg(s[rt], s[ls], s[rs], 1, S, 1);
}
void upd(int x, int y, int xx, int yy, int v, int l, int r, int rt)
{  //外层修改
    s[rt].upd(y, yy, v * (xx - x + 1), 1, S, 1);
    if (x == l && r == xx) {
        tag[rt].upd(y, yy, v, 1, S, 1);
        return;
    }
    Z;
    if (xx <= m)
        upd(x, y, xx, yy, v, l, m, ls);
    else {
        if (x > m)
            upd(x, y, xx, yy, v, m + 1, r, rs);
        else
            upd(x, y, m, yy, v, l, m, ls),
                upd(m + 1, y, xx, yy, v, m + 1, r, rs);
    }
}
int qh(int x, int y, int xx, int yy, int l, int r, int rt, int ad)
{  //查询（求和）
    if (x == l && r == xx)
        return s[rt].qh(y, yy, 1, S, 1, 0) + ad * (r - l + 1);
    Z;
    ad += tag[rt].qh(y, yy, 1, S, 1, 0);
    if (xx <= m)
        return qh(x, y, xx, yy, l, m, ls, ad);
    else {
        if (x > m)
            return qh(x, y, xx, yy, m + 1, r, rs, ad);
        else
            return qh(x, y, m, yy, l, m, ls, ad) +
                   qh(m + 1, y, xx, yy, m + 1, r, rs, ad);
    }
}
int main()
{
    cin >> D >> S >> q;
    build(1, D, 1);
}