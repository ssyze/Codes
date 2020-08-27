/*
 * @Date         : 2020-08-09 14:02:29
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a, b, fac[19];
int main()
{
    scanf("%llu%llu", &a, &b);
    int num = 0;
    ll tmp = a;
    while (tmp) {
        tmp /= 10;
        num++;
    }
    fac[0] = 1;
    for (int i = 1; i < 19; i++) fac[i] = fac[i - 1] * 10;
    int ans = 0;
    for (int i = 100; i <= 999; i++) {
        ll aa = i * fac[num] + a;
        if (aa % b == 0) ans++;
    }
    printf("%d\n", ans);
}