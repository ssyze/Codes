/*
 * @Date         : 2020-07-12 16:32:12
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v, a, b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x && y)
            v.push_back(t);
        else if (x)
            a.push_back(t);
        else if (y)
            b.push_back(t);
    }
    if (a.size() + v.size() < k || b.size() + v.size() < k) {
        cout << -1 << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < min(a.size(), b.size()); i++) v.push_back(a[i] + b[i]);
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < k; i++) sum += v[i];
    cout << sum << endl;
}