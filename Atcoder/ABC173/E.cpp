/*
 * @Date         : 2020-08-10 15:34:44
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll ans = 1;
    int l = 0, r = a.size() - 1;
    if (k & 1) ans = a[n - 1], k--, r--;
    int sz = a.size();
    if (ans < 0) {
        for (int i = 0; i < k; i++) ans = ans * a[sz - 2 - i] % mod;
    }
    else {
        while (k) {
            ll neg = a[l] * a[l + 1], pos = a[r] * a[r - 1];
            if (neg > pos)
                ans = ans * (neg % mod) % mod, l += 2;
            else
                ans = ans * (pos % mod) % mod, r -= 2;
            k -= 2;
        }
    }
    cout << (ans + mod) % mod << endl;
}