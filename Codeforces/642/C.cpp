/*
 * @Date         : 2020-05-14 22:48:09
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        long long sum = 0;
        n -= 2;
        long long tmp = 8, tmp1 = 1;
        for (int i = 1; i <= n; i += 2) {
            sum += tmp * tmp1;
            tmp += 8;
            tmp1++;
        }
        cout << sum << endl;
    }
}