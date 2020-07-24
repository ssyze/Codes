/*
 * @Date         : 2020-02-13 13:28:50
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
double r;
int i, j, n;
int main()
{
    cin >> n >> r;
    cin >> i >> j;
    double x = sqrt(r * r + r * r - 2.0 * r * r * cos(2.0 * pi / n));
    int a = min((i - j + n) % n, (j - i + n) % n);
    //cout << a << ' ' << x << endl;
    printf("%.6f\n", double(a) * x);
}