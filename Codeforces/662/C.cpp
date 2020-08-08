/*
 * @Date         : 2020-08-07 23:00:16
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int t, a[maxn], n;
vector<pair<int, int>> num;
map<int, int> mp;
bool check(int x)
{
    if (x >= n) return 0;
    if (x == 1) return 1;
    int sum = n, flag = 0;
    priority_queue<pair<int, int>> q;
    for (auto& x : num) q.push({x.second, x.first});
    for (;;) {
        int l = 0;
        for (int j = 0; j < num.size(); j++) {
            if (num1[j].second) {
                num1[j].second--, l++, sum--;
                cout << num[j].first << ' ';
            }
            if (l == x || sum == 0) break;
        }
        if (sum == 0) {
            flag = 1;
            break;
        }
        if (l != x) break;
    }
    cout << endl;
    if (flag)
        return 1;
    else
        return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        num.clear(), mp.clear();
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        for (auto& x : mp) num.push_back({x.first, x.second});
        sort(num.begin(), num.end(),
             [&](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
        int l = 1, r = 1e5 + 10, ans = 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            // cout << l << ' ' << r << endl;
            if (check(mid))
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        cout << ans - 1 << endl;
    }
}