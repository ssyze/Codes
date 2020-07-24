/*
 * @Date         : 2020-06-16 22:38:47
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
pair<int, int> p[maxn];
vector<pair<int, int>> point;
int x, y, n;
ll Sum(int pos)
{
    ll ans = 0;
    for (int i = 0; i < point.size(); i++) {
        if (point[i].first == point[i + 1].first) {
            if (point[i].second <= pos && point[i + 1].second > pos)
                ans = ans + 2 * (pos - point[i].second) + 2 * (point[i + 1].second - pos);
            else if (point[i].second >= pos)
                ans += 2 * (point[i + 1].second - pos);
            else
                ans += 2 * (pos - point[i].second);
            i++;
        } else
            ans += 2 * abs(point[i].second - pos);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    int k = unique(p, p + n) - p;
    for (int i = 0; i < k;) {
        point.push_back({ p[i].first, p[i].second });
        int j = i + 1;
        while (p[j].first == p[i].first)
            j++;
        --j;
        if (j != i)
            point.push_back({ p[j].first, p[j].second });
        i = j + 1;
    }
    ll sum = 0, num = 0;
    for (auto& x : point)
        sum += x.second;
    int pos = sum / point.size();
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = pos - 100; i <= pos + 100; i++) {
        if (i < 0 || i >= y)
            continue;
        ans = min(ans, Sum(i));
    }
    cout << ans + x - 1 << endl;
}