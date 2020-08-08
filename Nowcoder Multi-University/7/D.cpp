/*
 * @Date         : 2020-08-01 12:12:11
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n;
int main()
{
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        if (n == 1 || n == 24)
            puts("Fake news!");
        else
            puts("Nobody knows it better than me!");
    }
}