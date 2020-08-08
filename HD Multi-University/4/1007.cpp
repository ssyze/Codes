#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int tr[2][maxn << 2], a[2][maxn];

void pushup(int flag, int rt) { tr[flag][rt] = max(tr[flag][rt << 1], tr[flag][rt << 1 | 1]); }

void build(int flag, int l, int r, int rt)
{
    if (l == r) {
        tr[flag][rt] = a[flag][l];
        return;
    }
    int m = (l + r) >> 1;
    build(flag, l, m, rt << 1);
    build(flag, m + 1, r, rt << 1 | 1);
    pushup(flag, rt);
}

int query(int flag, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r) return tr[flag][rt];
    int m = (l + r) >> 1;
    int res = 0;
    if (L <= m) res = max(res, query(flag, L, R, l, m, rt << 1));
    if (R > m) res = max(res, query(flag, L, R, m + 1, r, rt << 1 | 1));
    return res;
}

int Find(int flag, int x, int l, int r, int rt)
{
    if (l == r) return l;
    int m = l + r >> 1;
    if (tr[flag][rt << 1] >= x)
        return Find(flag, x, l, m, rt << 1);
    else
        return Find(flag, x, m + 1, r, rt << 1 | 1);
}

void update(int flag, int L, int V, int l, int r, int rt)
{
    if (l == r) {
        tr[flag][rt] = V;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(flag, L, V, l, m, rt << 1);
    else
        update(flag, L, V, m + 1, r, rt << 1 | 1);
    pushup(flag, rt);
}

void add(int flag, int L, int V, int l, int r, int rt)
{
    if (l == r) {
        tr[flag][rt] = tr[flag][rt] + V;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        add(flag, L, V, l, m, rt << 1);
    else
        add(flag, L, V, m + 1, r, rt << 1 | 1);
    pushup(flag, rt);
}

void Free(int flag, int l, int r, int rt)
{
    tr[flag][rt] = 0;
    int m = l + r >> 1;
    if (l != r) {
        Free(flag, l, m, rt << 1);
        Free(flag, m + 1, r, rt << 1 | 1);
    }
}

pair<ll, ll> p[maxn];
int head[2][maxn], nxt[2][maxn];
ll c[2][maxn], cnt[2];

int idx(int flag, ll x) { return lower_bound(c[flag] + 1, c[flag] + cnt[flag] + 1, x) - c[flag]; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
        for (int i = 1; i <= n; ++i)
            c[0][i] = p[i].first + p[i].second, c[1][i] = p[i].second - p[i].first;
        sort(c[0] + 1, c[0] + 1 + n);
        cnt[0] = unique(c[0] + 1, c[0] + 1 + n) - c[0];
        sort(c[1] + 1, c[1] + 1 + n);
        cnt[1] = unique(c[1] + 1, c[1] + 1 + n) - c[1];
        for (int i = 0; i <= cnt[0]; ++i) head[0][i] = -1, a[0][i] = 0;
        for (int i = 0; i <= cnt[1]; ++i) head[1][i] = -1, a[1][i] = 0;
        for (int i = 1; i <= n; ++i) {
            int k_0 = p[i].first + p[i].second, k_1 = p[i].second - p[i].first;
            a[0][idx(0, k_0)]++;
            a[1][idx(1, k_1)]++;
            nxt[0][i] = head[0][idx(0, k_0)];
            head[0][idx(0, k_0)] = i;
            nxt[1][i] = head[1][idx(1, k_1)];
            head[1][idx(1, k_1)] = i;
        }
        build(0, 1, cnt[0], 1);
        build(1, 1, cnt[1], 1);
        int ans = 0, cur = 0;
        while (cur != n) {
            ans++;
            int p_0 = query(0, 1, cnt[0], 1, cnt[0], 1), p_1 = query(1, 1, cnt[1], 1, cnt[1], 1);
            if (p_0 > p_1) {
                cur += p_0;
                int x = Find(0, p_0, 1, cnt[0], 1);
                update(0, x, 0, 1, cnt[0], 1);
                for (int i = head[0][x]; i != -1; i = nxt[0][i])
                    add(1, idx(1, p[i].second - p[i].first), -1, 1, cnt[1], 1);
            }
            else {
                cur += p_1;
                int x = Find(1, p_1, 1, cnt[1], 1);
                update(1, x, 0, 1, cnt[1], 1);
                for (int i = head[1][x]; i != -1; i = nxt[1][i])
                    add(0, idx(0, p[i].first + p[i].second), -1, 1, cnt[0], 1);
            }
        }
        cout << ans << endl;
        Free(0, 1, cnt[0], 1);
        Free(1, 1, cnt[1], 1);
    }
    return 0;
}