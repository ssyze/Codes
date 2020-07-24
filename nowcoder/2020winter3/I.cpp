#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[65], b[65], c[65], d[65], s;
int n;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}
int main()
{
    cin >> n;
    a[1] = 0;
    a[2] = 1;
    a[3] = 1;
    b[1] = 1;
    b[2] = 1;
    c[1] = 0;
    c[2] = 0;
    c[3] = 1;
    c[4] = 1;
    d[1] = 0;
    d[2] = 0;
    d[3] = 0;
    d[4] = 2;
    d[5] = 2;
    for (int i = 4; i <= n; i++) {
        if (i & 1)
            a[i] = a[i - 1];
        else
            a[i] = a[i - 1] * 4 - (i / 2 - 2);
    }
    for (int i = 3; i <= n; i++) {
        if (i & 1)
            b[i] = b[i - 1] * 4 - i + 2;
        else
            b[i] = b[i - 1];
    }
    for (int i = 5; i <= n; i++) {
        if (i & 1)
            c[i] = c[i - 1] * 4 + (i - 1) / 2;
        else
            c[i] = c[i - 1];
    }
    for (int i = 6; i <= n; i++) {
        if (i & 1)
            d[i] = d[i - 1];
        else
            d[i] = d[i - 1] * 4 + i - 2;
    }
    printf("A->B:%lld\n", a[n]);
    printf("A->C:%lld\n", b[n]);
    printf("B->A:%lld\n", c[n]);
    printf("B->C:%lld\n", a[n]);
    printf("C->A:%lld\n", d[n]);
    printf("C->B:%lld\n", c[n]);
    printf("SUM:%lld\n", qpow(2, n) - 1);
}