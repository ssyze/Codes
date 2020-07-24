/*
 * @Date         : 2020-07-21 14:15:03
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int P = 1000000009;
const int INV2 = 500000005;
const int SQRT5 = 383008016;
const int INVSQRT5 = 276601605;
const int Aa = 691504013;
const int Bb = 308495997;

const int N = 100005;

ll A, B;
ll n, K, cc;
ll fac[N], inv[N];
ll pa[N], pb[N];

inline void Pre(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = (P - P / i) * inv[P % i] % P;
    inv[0] = 1;
    for (int i = 1; i <= n; i++) inv[i] = inv[i] * inv[i - 1] % P;
    pa[0] = 1;
    for (int i = 1; i <= n; i++) pa[i] = pa[i - 1] * A % P;
    pb[0] = 1;
    for (int i = 1; i <= n; i++) pb[i] = pb[i - 1] * B % P;
}

inline ll C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }

inline ll Pow(ll a, ll b)
{
    ll ret = 1;
    for (; b; b >>= 1, a = a * a % P)
        if (b & 1) ret = ret * a % P;
    return ret;
}

inline ll Inv(ll x) { return Pow(x, P - 2); }

inline void Solve()
{
    ll Ans = 0;
    for (int j = 0; j <= K; j++) {
        ll t = pa[K - j] * pb[j] % P, tem;
        tem = t == 1 ? n % P : t * (Pow(t, n) - 1 + P) % P * Inv(t - 1) % P;
        if (~j & 1)
            Ans += C(K, j) * tem % P, Ans %= P;
        else
            Ans += P - C(K, j) * tem % P, Ans %= P;
    }
    Ans = Ans * Pow(INVSQRT5, K) % P;
    printf("%lld\n", Ans);
}

int main()
{
    int T;
    // freopen("t.in","r",stdin);
    // freopen("t.out","w",stdout);

    scanf("%d", &T);
    while (T--) {
        A = Aa;
        B = Bb;

        scanf("%lld%lld%lld", &n, &cc, &K);
        A = Pow(A, cc);
        B = Pow(B, cc);
        Pre(100000);

        Solve();
    }
}