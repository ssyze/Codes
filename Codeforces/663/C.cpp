/*
 * @Date         : 2020-08-09 22:47:52
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int f[15];
vector<int> g[15];
ll qpow(ll a, ll b)
{
    a %= mod, b %= mod - 1;
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    for (int i = 1; i <= 10; i++) {
        int ans = 0;
        a.push_back(i);
        sort(a.begin(), a.end());
        do {
            // for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
            // cout << endl;
            int flag = 0;
            for (int i = 0; i <= a.size(); i++) f[i] = i, g[i].clear();
            for (int i = 0; i < a.size(); i++) {
                int ps = -1;
                for (int j = 0; j <= i - 1; j++) {
                    if (a[j] > a[i]) ps = j;
                }
                if (ps != -1) {
                    int fx = find(i + 1), fy = find(ps + 1);
                    if (fx == fy) {
                        flag = 1;
                        break;
                    }
                    f[fx] = fy;
                }
                ps = -1;
                for (int j = i + 1; j < a.size(); j++)
                    if (a[j] > a[i]) {
                        ps = j;
                        break;
                    }
                if (ps != -1) {
                    int fx = find(i + 1), fy = find(ps + 1);
                    if (fx == fy) {
                        flag = 1;
                        break;
                    }
                    f[fx] = fy;
                }
            }
            /* for (int i = 1; i <= a.size(); i++) {
                int fx = find(i);
                for (auto& x : g[i]) {
                    if (x == i) continue;
                    int fy = find(x);
                    if (fx == fy) {
                        cout << i << ' ' << x << endl;
                        flag = 1;
                        break;
                    }
                    f[fx] = fy;
                }
                if (flag) break;
            } */
            if (flag) ans++;
        } while (next_permutation(a.begin(), a.end()));
        cout << a.size() << ' ' << ans << endl;
    }
}