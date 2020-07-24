/*
 * @Date         : 2020-03-28 17:55:36
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    while (cin >> n) {
        int ans = 0;
        while (n >= 100)
            n -= 100, ans++;
        while (n >= 50)
            n -= 50, ans++;
        while (n >= 10)
            n -= 10, ans++;
        while (n >= 5)
            n -= 5, ans++;
        while (n >= 2)
            n -= 2, ans++;
        while (n >= 1)
            n--, ans++;
        cout << ans << endl;
    }
}