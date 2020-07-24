/*
 * @Date         : 2020-07-23 13:41:38
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
int t, n, k;
ll ans;
struct item {
    int a, b, c, d;
    item() {}
    item(int _a, int _b, int _c, int _d) : a(_a), b(_b), c(_c), d(_d) {}
    item operator+(const item& x) const { return item(a + x.a, b + x.b, c + x.c, d + x.d); }
};
vector<item> it[maxn];
vector<int> f;
ll DMG(item a) { return 1LL * (100 + a.a) * (100 + a.b) * (100 + a.c) * (100 + a.d); }
void dfs(int i, item now)
{
    if (i > k) {
        ans = max(ans, DMG(now));
        return;
    }
    int tmp = f[i - 1];
    if (it[tmp].size() == 0) dfs(i + 1, now);
    for (auto& x : it[tmp]) {
        dfs(i + 1, now + x);
    }
}
int main()
{
    // cout << 1LL * 100 * 100 * 100 * 100 * 100 * 100 * 100 << endl;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            int type, q, w, e, r;
            scanf("%d%d%d%d%d", &type, &q, &w, &e, &r);
            it[type].push_back(item(q, w, e, r));
        }
        for (int i = 1; i <= k; i++) f.push_back(i);
        shuffle(f.begin(), f.end(), default_random_engine(time(0)));
        item now(0, 0, 0, 0);
        ans = 0;
        dfs(1, now);
        cout << ans << '\n';
        for (int i = 0; i <= k; i++) it[i].clear();
        f.clear();
    }
}