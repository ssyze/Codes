#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
pair<int, int> a[maxn], b[maxn];
int pos[10000005];
int n, m, ans, up;
int check(int x)
{
    int sum = x, mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first + x > up) continue;
        int tmp = pos[a[i].first + x];
        if (tmp >= a[i].second) mx = max({ mx, tmp - a[i].second + 1 });
    }
    sum += mx;
    // cout << mx << ' ' << sum << endl;
    if (sum < ans)
        return sum;
    else
        return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
    for (int i = 0; i < m; i++) up = max(up, b[i].first);
    sort(b, b + m, [&](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    });
    for (int i = 0; i < m; i++) {
        // if (i && b[i].first == b[i - 1].first) continue;
        if (pos[b[i].first] >= b[i].second) continue;
        int cur = lower_bound(pos, pos + up + 1, b[i].second, greater<int>()) - pos;
        for (int j = cur; j <= b[i].first; j++) {
            pos[j] = max(pos[j], b[i].second);
            // cout << j << ' ' << pos[j] << endl;
        }
        cur = b[i].first + 1;
    }
    // for (int i = 0; i < 15; i++) cout << pos[i] << ' ';
    // cout << endl;
    int l = 0, r = 4e6;
    ans = 4e6;
    while (l <= r) {
        int mid = (l + r) >> 1;
        // cout << l << ' ' << r << ' ' << mid << ' ';
        int tmp = check(mid);
        if (tmp != -1)
            r = mid - 1, ans = tmp;
        else
            l = mid + 1;
    }
    int mid = (l + r) / 2;
    for (int i = max(0, mid - 50000); i <= mid + 50000; i++) {
        int sum = i, mx = 0;
        for (int j = 0; j < n; j++) {
            if (a[j].first + i > up) continue;
            int tmp = pos[a[j].first + i];
            if (tmp >= a[j].second) mx = max(mx, tmp - a[j].second + 1);
        }
        ans = min(ans, sum + mx);
    }
    cout << ans << endl;
}