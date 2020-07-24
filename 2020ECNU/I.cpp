/*
 * @Date         : 2020-05-23 14:09:21
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    string ans = "b";
    for (int i = 0; i < k - 1; i++)
        ans += 'a';
    for (int i = ans.length(); i < n; i++)
        ans += 'c';
    cout << ans << endl;
}