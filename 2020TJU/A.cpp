/*
 * @Date         : 2020-05-10 12:51:01
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n, a, b;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        int g = __gcd(a, b);
        int num = n / g;
        num -= 2;
        if (num & 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}