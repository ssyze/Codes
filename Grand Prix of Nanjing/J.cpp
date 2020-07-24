/*
 * @Date         : 2020-05-03 16:10:56
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t;
unsigned long long n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        n--;
        while (n) {
            if (n & 1)
                ans++;
            n >>= 1;
        }
        cout << (1ULL << ans) << endl;
    }
}