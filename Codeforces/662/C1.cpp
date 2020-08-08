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
    vector<int> lst;
    map<int, int> vis;
    priority_queue<pair<int, int>> q;
    for (auto& x : num) q.push({x.second, x.first});
    for (;;) {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < x; i++) {
            tmp.push_back(q.top());
            q.pop();
            sum--;
            if (sum == 0 || q.empty()) break;
        }
        for (int i = 0; i < tmp.size(); i++) {
            lst.push_back(tmp[i].second);
            if (tmp[i].first > 1) q.push({tmp[i].first - 1, tmp[i].second});
        }
        if (sum == 0) break;
    }
    if (lst.size() < n) return 0;
    for (int i = 0; i < lst.size(); i++) {
        if (vis.find(lst[i]) == vis.end())
            vis[lst[i]] = i + 1;
        else {
            int len = (i + 1) - vis[lst[i]];
            if (len < x) {
                return 0;
            }
            vis[lst[i]] = i + 1;
        }
    }
    return 1;
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