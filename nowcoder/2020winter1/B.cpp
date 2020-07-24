/*
 * @Date         : 2020-02-04 13:03:40
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, a, b, sum1, sum2;
double x, sum;
int main()
{
    cin >> n >> x >> a >> b;
    sum1 = n * a;
    sum2 = n * b;
    x = x / 100.0;
    sum = sum1 * x + sum2 * (1.0 - x);
    printf("%.2f\n", sum);
}