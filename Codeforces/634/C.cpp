/*
 * @Date         : 2020-05-01 00:37:43
 * @Author       : ssyze
 * @Description  : 三行的题写了60行 我是真垃圾
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n;
pair<int, int> p[maxn];
vector<int> v;
bool check(int mid)
{
    if (mid > v.size())
        return 0;
    int pos = 0;
    for (; pos < n; pos++) {
        if (mid <= p[pos].first) {
            int tmp = v.size();
            if (mid == p[pos].first)
                tmp--;
            if (mid <= tmp)
                return 1;
        }
    }
    return 0;
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <= n; i++) {
            p[i].first = 0;
            p[i].second = i;
        }
        v.clear();
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            p[x].first++;
            v.push_back(x);
        }
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        sort(p, p + n + 1, [&](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int l = 0, r = n, ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            //cout << l << ' ' << r << ' ' << mid << endl;
            if (check(mid))
                l = mid + 1;
            else
                r = mid - 1;
            //cout << l << ' ' << r << ' ' << mid << endl;
        }
        cout << r << endl;
    }
}