/*
 * @Date         : 2020-02-13 15:08:48
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int t;
int main()
{
    cin >> t;
    while (t--) {
        double a, b;
        scanf("%lf%lf", &a, &b);
        if ((a <= 0 && b <= 0) || (a >= 0 && b >= 0)) {
            a = abs(a);
            b = abs(b);
            if (b >= a) {
                printf("%.9f\n", b - a);
                continue;
            }
            double ans = 0.0;
            while (pow(a, 1.0 / 3) >= b && (a - pow(a, 1.0 / 3) - 1 > eps)) {
                a = pow(a, 1.0 / 3);
                ans = ans + 1;
            }
            if (pow(a, 1.0 / 3) >= b)
                ans = ans + a - b;
            else
                ans = ans + min(b - pow(a, 1.0 / 3) + 1, a - b);
            printf("%.9f\n", ans + eps);
        }
        else {
            if (a <= 0)
                a = abs(a);
            double ans = 0.0;
            while ((a - pow(a, 1.0 / 3)) - 1 > eps) {
                ans = ans + 1;
                a = pow(a, 1.0 / 3);
            }
            ans = ans + a + abs(b);
            printf("%.9f\n", ans + eps);
        }
    }
}