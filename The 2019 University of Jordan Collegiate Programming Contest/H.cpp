/*
 * @Date         : 2020-01-29 12:45:51
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int v, s;
int main()
{
    cin >> v >> s;
    double r = s / (2 * sin(pi / v));
    double ans = 0.5 * pi * r * r;
    printf("%.8f\n", ans);
}