/*
    * @Date         : 2020-02-11 14:01:25
    * @Author       : ssyze
    * @Description  : 
    */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
int a[maxn];
int n, k;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int have0(int x)
{
    for (int i = 0; i < k; i++) {
        if (a[i + x] == 0)
            return i + x;
    }
    return -1;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 1, ans = 0;
    int l = 0, r = 0;
    while (r < n) {
        if (a[r] == 0) {
            l = r + 1;
            sum = 1;
        }
        else
            sum = sum * a[r] % mod;
        if (r - l + 1 == k) {
            ans = max(ans, sum);
            sum = sum * qpow(a[l], mod - 2) % mod;
            l++;
        }
        r++;
    }
    cout << ans % mod << endl;
}