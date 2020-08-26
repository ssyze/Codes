/*
 * @Date         : 2020-08-20 19:38:09
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int t, n, m, k;
vector<pair<int, int>> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        v.clear();
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            v.push_back({ x, i });
        }
        sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        if (k == 0)
            for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
        else
            for (int i = 1; i <= n; i++) cout << v[i - 1].second << " \n"[i == n];
    }
}