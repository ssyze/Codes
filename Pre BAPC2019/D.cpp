/*
 * @Date         : 2020-03-14 14:45:01
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
long double ans1;
long double n, m;
int main()
{
    cin >> n >> m;
    if (m == 1) {
        for (int i = 1; i <= n; i++) {
            ans1 += (1.0 / n) * i;
        }
        printf("%.8Lf\n", ans1);
        return 0;
    }
    long double avg = (n + 1) / 2.0;
    for (int num = 1; num <= n - 1; num++) {
        long double ans = 0;
        int num1 = n - num;
        long double p = num1 / n;
        long double _p = p;
        for (int i = 1; i < m - 1; i++)
            _p *= p;
        _p *= 1.0 / n;
        //cout << _p << endl;
        long double p1 = (1 - _p * num1) / num;
        //cout << p1 << endl;
        //cout << num << ' ' << num1 << endl;
        for (int i = 1; i <= num1; i++)
            ans += _p * i;
        for (int i = num1 + 1; i <= n; i++)
            ans += p1 * i;
        ans1 = max(ans, ans1);
    }
    printf("%.8Lf\n", ans1);
}