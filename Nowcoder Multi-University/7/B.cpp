/*
 * @Date         : 2020-08-01 14:07:54
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int t, n, m;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        /* if (n == m) {
            cout << n << '\n';
            for (int i = 0; i < n; i++) cout << n << ' ';
            cout << '\n';
            continue;
        } */
        if (n < m) swap(n, m);
        for (int i = 0; i < n; i++) ans.push_back(m);
        while (n % m != 0) {
            int nn = n, mm = m;
            n = mm;
            m = nn % mm;
            int sum = n * m;
            ans.resize(ans.size() - m + n);
            for (int i = ans.size() - n; i < ans.size(); i++) ans[i] = m;
        }
        cout << ans.size() << '\n';
        for (auto& x : ans) cout << x << ' ';
        cout << '\n';
        ans.clear();
    }
}