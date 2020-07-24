/*
 * @Date         : 2020-03-24 15:20:28
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
vector<int> a[maxn];
int visg[maxn], visb[maxn];
int t, n, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            visg[i] = inf;
            visb[i] = inf;
        }
        for (int i = 1; i <= n; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                //cout << x << endl;
                a[i].push_back(x);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (auto& x : a[i]) {
                if (visb[x] == inf) {
                    visb[x] = 0;
                    visg[i] = 0;
                    ans++;
                    break;
                }
            }
        }
        if (ans == n) {
            cout << "OPTIMAL" << endl;
        }
        else {
            int pos = 0, pos1 = 0;
            for (int i = 1; i <= n; i++) {
                if (visg[i] == inf && !pos) {
                    pos = i;
                }
                if (visb[i] == inf && !pos1) {
                    pos1 = i;
                }
                if (pos && pos1)
                    break;
            }
            cout << "IMPROVE" << endl;
            cout << pos << ' ' << pos1 << endl;
        }
        for (int i = 1; i <= n; i++) {
            a[i].clear();
        }
    }
}