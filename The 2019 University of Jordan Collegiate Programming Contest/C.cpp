/*
 * @Date         : 2020-01-29 12:30:17
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s, x;
    cin >> s >> x;
    int ans = 0;
    while (s) {
        s /= x;
        ans++;
    }
    cout << ans << endl;
}