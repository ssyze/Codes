/*
 * @Date         : 2020-08-09 01:21:15
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;

int a[maxn << 1], tree[maxn << 1], vis[maxn], ans[maxn], n, q;
struct point {
    int l, r, id;
} qs[maxn];

inline int lowbit(int x) { return x & -x; }

void add(int pos, int val)
{
    while (pos <= n) tree[pos] += val, pos += lowbit(pos);
}

int query(int pos)
{
    int res = 0;
    while (pos > 0) res += tree[pos], pos -= lowbit(pos);
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].id = i;
    }
    sort(qs + 1, qs + q + 1, [&](point a, point b) { return a.r < b.r; });
    int st = 1;
    for (int i = 1; i <= q; i++) {
        for (int j = st; j <= qs[i].r; j++) {
            if (!vis[a[j]]) {
                vis[a[j]] = j;
                add(j, 1);
            }
            else if (vis[a[j]]) {
                add(vis[a[j]], -1);
                vis[a[j]] = j;
                add(j, 1);
            }
        }
        st = qs[i].r + 1;
        ans[qs[i].id] = query(qs[i].r) - query(qs[i].l - 1);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}