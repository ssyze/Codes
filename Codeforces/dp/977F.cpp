/*
 * @Date         : 2020-04-11 15:36:33
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, a[maxn];
map<int, int> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[a[i]] = 0;
    }
    int ans = 0, len = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        dp[x] = dp[x - 1] + 1;
        if (len < dp[x]) {
            len = dp[x];
            ans = x;
        }
        //cout << dp[a[i]] << endl;
    }
    //cout << len << endl;
    vector<int> v;
    for (int i = n; i >= 1; i--) {
        if (a[i] == ans) {
            v.push_back(i);
            ans--;
        }
    }
    cout << v.size() << endl;
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
    cout << endl;
}