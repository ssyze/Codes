/*
 * @Date         : 2020-08-26 14:54:51
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5, P = 1e9 + 7, Inv2 = (P + 1) / 2;
typedef long long ll;
struct Data {
    int d, m, w, id;
};
int n, m, q, Ans[10005];
int is[N], prime[N], f[N], g[N];
vector<Data> Q;
int main()
{
    n = 1e7;
    f[1] = g[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!is[i]) prime[++prime[0]] = i, f[i] = 2, g[i] = P - Inv2;
        for (int j = 1, x; j <= prime[0] && (x = i * prime[j]) <= n; ++j) {
            is[x] = 1;
            if (i % prime[j])
                f[x] = 2 * f[i] % P, g[x] = (ll)g[prime[j]] * g[i] % P;
            else {
                f[x] = f[i];
                break;
            }
        }
    }
    scanf("%d", &q);
    for (int T = 1; T <= q; ++T) {
        scanf("%d%d", &n, &m);
        int t = n;
        vector<int> div;
        for (int d = 2; d * d <= t; ++d)
            if (t % d == 0) {
                div.push_back(d);
                while (t % d == 0) t /= d;
            }
        if (t != 1) div.push_back(t);
        for (int s = 0; s < (1 << div.size()); ++s) {
            int d = 1;
            for (int i = 0; i <= (int)div.size() - 1; ++i)
                if (s & (1 << i)) d *= div[i];
            if (m < d || !g[d]) continue;
            Q.push_back({ d, (m / d) * d, int((ll)f[n] * g[d] % P), T });
        }
    }
    sort(Q.begin(), Q.end(), [](Data a, Data b) { return a.d == b.d ? a.m < b.m : a.d < b.d; });
    ll w;
    int d = 0, i;
    for (auto t : Q) {
        if (t.d != d) d = i = t.d, w = 0;
        for (; i <= t.m; i += d) w += f[i];
        Ans[t.id] = (Ans[t.id] + (ll)t.w * (w %= P) % P) % P;
    }
    for (int i = 1; i <= q; ++i) printf("%d\n", Ans[i]);
    return 0;
}