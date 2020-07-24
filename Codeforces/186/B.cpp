/*
 * @Date         : 2019-12-17 21:12:58
 * @Author       : ssyze
 * @Description  : 
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
string s;
int n;
int sum[maxn];
int main()
{
    cin >> s;
    cin >> n;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == s[i + 1]) {
            sum[i + 1] = sum[i] + 1;
        } else
            sum[i + 1] = sum[i];
    }
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << sum[r] - sum[l] << endl;
    }
}