/*
 * @Date         : 2020-07-22 00:55:36
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 5;
int T, n, flag1[maxn], stk[maxn], flag2[maxn], id[maxn];
struct robot {
    int p, a;
    bool operator<(const robot &x) { return p == x.p ? a > x.a : p > x.p; }
    bool operator==(const robot &x) { return p == x.p && a == x.a; }
} rbt[maxn], rbt1[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("leading-robots.in", "r", stdin);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> rbt[i].p >> rbt[i].a;
        sort(rbt, rbt + n);
        for (int i = 1; i < n; i++) {
            if (rbt[i] == rbt[i - 1]) flag1[i] = flag1[i - 1] = t;
        }
        int nn = 0;
        for (int i = 0; i < n; i++) {
            if (nn == 0 || rbt[i].a > rbt1[nn - 1].a) {
                rbt1[nn++] = rbt[i];
                if (flag1[i] == t) flag2[nn - 1] = t;
            }
        }
        n = nn;
        int ans = 0;
        stk[ans++] = 0;
        if (n > 1) stk[ans++] = 1;
        for (int i = 2; i < n; i++) {
            while (ans > 1) {
                int t1 = stk[ans - 1], t2 = stk[ans - 2];
                int s1 = rbt1[t1].p - rbt1[i].p, s2 = rbt1[t2].p - rbt1[t1].p;
                int a1 = rbt1[i].a - rbt1[t1].a, a2 = rbt1[t1].a - rbt1[t2].a;
                if ((ll)s1 * a2 > (ll)s2 * a1) break;
                ans--;
            }
            stk[ans++] = i;
        }
        int res = ans;
        for (int i = 0; i < ans; i++) {
            if (flag2[stk[i]] == t) res--;
        }
        cout << res << '\n';
    }
}