#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
int t, n, Case;
ll a[maxn], b[maxn], p[maxn], mn[maxn], pos[maxn], mx[maxn][100];
vector<ull> post, neg;
ll askmx(int l, int r)
{
    int k = log2(r - l + 1);
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
void init()
{
    for (int i = 0; i <= n; ++i) mx[i][0] = p[i];
    for (int j = 1; (1 << j) <= n + 1; ++j)
        for (int i = 0; i + (1 << j) <= n + 1; ++i)
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
}
int main()
{
    freopen("I.in", "r", stdin);
    freopen("K.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(mn, 0x3f, sizeof(mn));
        for (int i = 1; i <= n; i++) scanf("%lld", a + i);
        for (int i = 1; i <= n; i++) scanf("%lld", b + i);
        ll mx = -0x3f3f3f3f3f3f3f3f, ps, ans = b[1], sum1 = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + a[i];
            mn[i] = min(b[i], mn[i - 1]);
            if (p[i] > mx) {
                mx = p[i];
                ps = i;
            }
        }
        init();
        if (p[ps] * mn[ps] >= 0)
            post.push_back(p[ps] * mn[ps]);
        else
            neg.push_back(-p[ps] * mn[ps]);
        sum1 += mn[ps];
        for (int i = ps;;) {
            int j, k;
            for (j = i - 1, 1; j >= 1; j--) {
                if (mn[j] > mn[i]) break;
            }
            if (j <= 0) break;
            int l = 1, r = j;
            mx = askmx(l, r);
            while (l <= r) {
                int mid = (l + r) / 2;
                // cout << l << ' ' << r << endl;
                if (askmx(1, mid) >= mx) {
                    r = mid - 1, ps = mid;
                }
                else
                    l = mid + 1;
            }
            ll res = p[ps] * (mn[ps] - sum1);
            if (res >= 0)
                post.push_back(ull(res));
            else
                neg.push_back(ull(-res));
            i = ps;
            sum1 += (mn[ps] - sum1);
        }
        ull spos = 0, sneg = 0;
        for (int i = 0; i < post.size(); ++i) spos += post[i];
        for (int i = 0; i < neg.size(); ++i) sneg += neg[i];
        post.clear();
        neg.clear();
        bool neg = sneg > spos;
        printf("Case #%d: %lld ", ++Case, ans);
        if (neg)
            printf("-%llu\n", sneg - spos);
        else
            printf("%llu\n", spos - sneg);
    }
}
