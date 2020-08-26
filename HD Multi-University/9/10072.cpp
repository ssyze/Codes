#include <bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long LL;
mt19937 rnd(time(0));
const int N = 6e5 + 10;
int n, q, a[N], cnt;
LL sum[N];
int ch[N][2], sz[N], val[N], pri[N], mi[N], num, rt, x, y, z, zz, x1, x2, x3, x4, x5, x6;
char *fs, *ft, buf[1 << 20];
#define gc() (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 20, stdin), fs == ft)) ? 0 : *fs++;
inline int read()
{
    int x = 0, f = 1;
    char ch = gc();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = gc();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = gc();
    }
    return x * f;
}
inline void init()
{
    num = rt = 0;
    mi[0] = 2000000000;
    sum[0] = 0;
    memset(ch, 0, sizeof ch), memset(sz, 0, sizeof sz);
}
inline void push_up(int p)
{
    sz[p] = sz[ch[p][0]] + sz[ch[p][1]] + 1;
    mi[p] = min(val[p], min(mi[ch[p][0]], mi[ch[p][1]]));
    sum[p] = sum[ch[p][0]] + sum[ch[p][1]] + val[p];
}
inline int get(int v)
{
    sz[++num] = 1;
    val[num] = sum[num] = mi[num] = v;
    pri[num] = rnd();
    return num;
}
void split(int now, int k, int& x, int& y)
{
    if (!now) return (void)(x = y = 0);
    if (k <= sz[ch[now][0]])
        y = now, split(ch[now][0], k, x, ch[now][0]);
    else
        x = now, split(ch[now][1], k - sz[ch[now][0]] - 1, ch[now][1], y);
    push_up(now);
}
void split_val(int now, int k, int& x, int& y)
{
    if (!now) return void(x = y = 0);
    if (val[now] >= k && mi[ch[now][1]] >= k)
        y = now, split_val(ch[now][0], k, x, ch[now][0]);
    else
        x = now, split_val(ch[now][1], k, ch[now][1], y);
    push_up(now);
}
int merge(int x, int y)
{
    if (!x || !y) return x + y;
    if (pri[x] < pri[y]) {
        ch[x][1] = merge(ch[x][1], y);
        push_up(x);
        return x;
    }
    else {
        ch[y][0] = merge(x, ch[y][0]);
        push_up(y);
        return y;
    }
}
inline void insert(int p, int v)
{
    split(rt, p - 1, x, y);
    rt = merge(merge(x, get(v)), y);
}
inline int kth(int k)
{
    split(rt, k, x, y);
    split(x, k - 1, z, zz);
    int res = val[zz];
    rt = merge(merge(z, zz), y);
    return res;
}
inline LL calc(int x, int y)
{
    if (kth(x) < y) return 0LL;
    int ls, rs;
    split(rt, x, ls, rs);
    if (mi[ls] >= y) return rt = merge(ls, rs), 0LL;
    split_val(ls, y, z, zz);
    LL res = sum[zz] - 1LL * (y - 1) * sz[zz];
    split(zz, 1, x1, x2);
    int tmp = val[x1] - y + 1, cnt = sz[z], cntx2 = sz[x2];
    split(z, cnt - 1, x3, x4);
    int v4 = val[x4] + tmp;
    rt = merge(merge(x3, x2), rs);
    insert(cnt, v4), insert(x, y - 1);
    return res;
}
void dfs(int now)
{
    if (ch[now][0]) dfs(ch[now][0]);
    a[++cnt] = val[now];
    if (ch[now][1]) dfs(ch[now][1]);
}
void solve()
{
    n = read(), q = read();
    init();
    cout << n << ' ' << q << endl;
    cnt = 0;
    for (int i = 1; i <= n; i++) a[i] = read(), insert(i, a[i]);
    for (int i = 1, op, x, y; i <= q; i++) {
        op = read(), x = read();
        if (op == 1)
            y = read(), printf("%lld\n", calc(x, y));
        else
            printf("%d\n", kth(x));
        dfs(rt);
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << endl;
    }
    dfs(rt);
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
}
signed main()
{
    int T;
    T = read();
    while (T--) solve();
    return 0;
}