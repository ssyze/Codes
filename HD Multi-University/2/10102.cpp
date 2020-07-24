/*
 * @Date         : 2020-07-23 14:39:38
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, k;
struct item {
    int a, b, c, d;
    item() {}
    item(int _a, int _b, int _c, int _d) : a(_a), b(_b), c(_c), d(_d) {}
};
vector<item> it[55];
ll f(item a)
{
    ll sum1 = 1LL * a.a * a.a + 1LL * a.b * a.b + 1LL * a.c * a.c + 1LL * a.d + a.d;
    ll sum2 = a.a + a.b + a.c + a.d;
    return sum1 - sum2 * sum2;
}
bool cmp(item a, item b)
{
    ll suma = a.a + a.b + a.c + a.d;
    ll sumb = b.a + b.b + b.c + b.d;
    if (suma == sumb)
        return f(a) < f(b);
    else
        return suma > sumb;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int type, q, w, e, r;
            cin >> type >> q >> w >> e >> r;
            it[type].push_back(item(q, w, e, r));
        }
        item now(0, 0, 0, 0);
        for (int i = 1; i <= k; i++) {
            if (it[i].size() == 0) continue;
            sort(it[i].begin(), it[i].end(), cmp);
            int sum = it[i][0].a + it[i][0].b + it[i][0].c + it[i][0].d, pos = 0;
            item tmp = now;
            tmp.a = now.a + it[i][0].a, tmp.b = now.b + it[i][0].b;
            tmp.c = now.c + it[i][0].c, tmp.d = now.d + it[i][0].d;
            ll f1 = f(tmp);
            for (int j = 1; i < it[j].size(); j++) {
                int sum1 = it[i][j].a + it[i][j].b + it[i][j].c + it[i][j].d;
                if (sum1 < sum) break;
                tmp.a = now.a + it[i][j].a, tmp.b = now.b + it[i][j].b;
                tmp.c = now.c + it[i][j].c, tmp.d = now.d + it[i][j].d;
                ll f2 = f(tmp);
                if (f2 < f1) {
                    pos = j;
                    f1 = f2;
                }
            }
            now.a += it[i][pos].a, now.b += it[i][pos].b;
            now.c += it[i][pos].c, now.d += it[i][pos].d;
            // cout << it[i][0].a << ' ' << i << endl;
        }
        cout << 1LL * (100 + now.a) * (100 + now.b) * (100 + now.c) * (100 + now.d) << '\n';
    }
}