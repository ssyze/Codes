/*
 * @Date         : 2020-04-01 15:34:21
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector<int> v[12];
int a[maxn], ans[maxn], t, n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        v[1].push_back(a[1]);
        ans[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= 11; j++) {
                if (v[j].empty()) {
                    v[j].push_back(a[i]);
                    ans[i] = j;
                    break;
                }
                int flag = 0;
                for (auto& x : v[j]) {
                    if (__gcd(a[i], x) == 1) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    v[j].push_back(a[i]);
                    ans[i] = j;
                    break;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= 11; i++)
            if (!v[i].empty())
                cnt++;
        cout << cnt << endl;
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
        for (int i = 1; i <= 11; i++)
            v[i].clear();
    }
}