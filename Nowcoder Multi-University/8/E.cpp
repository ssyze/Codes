/*
 * @Date         : 2020-08-04 18:48:25
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>

using namespace std;
const int maxn = 4e5 + 5;
long long a[maxn], d[maxn], t, l, r, Case;

void init()
{
    int lim = 1e5;
    for (int l = 3; l <= lim - 2; l++) {
        for (int j = 1; j * l + 3 <= lim; j++) {
            int left = l * j + 3;
            a[left]++, a[left + 2 * l - 4]--;
            d[left + l - 2]++, d[left + 2 * l - 4]--;
        }
    }
    for (int i = 2; i <= lim; i++) a[i] += a[i - 2], d[i] += d[i - 1];
    for (int i = 1; i <= lim; i++) a[i] -= d[i];
    for (int i = 1; i <= lim; i++) a[i] += a[i - 1];
    for (int i = 1; i <= lim; i++) a[i] += a[i - 1];
}

int main()
{
    init();
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &l, &r);
        printf("Case #%lld: %lld\n", ++Case, a[r] - a[l - 1]);
    }
}