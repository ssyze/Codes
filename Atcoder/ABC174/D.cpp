/*
 * @Date         : 2020-08-09 00:34:04
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> r, w;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W')
            w.push_back(i);
        else
            r.push_back(i);
    }
    reverse(r.begin(), r.end());
    int ans = 0;
    for (int i = 0; i < min(w.size(), r.size()); i++) {
        if (r[i] > w[i]) {
            swap(s[r[i]], s[w[i]]);
            ans++;
        }
    }
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') flag = 1;
        if (flag && s[i] == 'R') ans++;
    }
    cout << ans << endl;
}