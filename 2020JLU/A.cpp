/*
 * @Date         : 2020-06-13 13:08:48
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
int t;
string s;
int suf[100005];
ll fac[100005];
ll count(string a)
{
    ll sum = 0;
    if (a[0] > '7')
        sum = fac[a.length() - 1] % mod;
    else if (a[0] == '7')
        sum = (sum + suf[1] + 1) % mod;
    ll tmp = a[0] - '0';
    int len = a.length() - 1;
    //cout << sum << endl;
    for (int i = 1; i < a.length(); i++) {
        sum = sum + (tmp * fac[len - 1] % mod);
        sum %= mod;
        if (a[i] > '7')
            sum = (sum + fac[len - 1]) % mod;
        else if (a[i] == '7')
            sum = (sum + suf[i + 1] + 1) % mod;
        tmp = (tmp * 10 + a[i] - '0') % mod;
        //cout << tmp << endl;
        len--;
        //cout << sum << endl;
    }
    return sum;
}
int main()
{
    //cout << qpow(2, 3) << endl;
    cin >> t;
    while (t--) {
        cin >> s;
        ll sum1 = 0, p = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            suf[i] = ((s[i] - '0') * p + suf[i + 1]) % mod;
            p = p * 10 % mod;
        }
        fac[0] = 1;
        for (int i = 1; i <= s.length(); i++)
            fac[i] = fac[i - 1] * 10 % mod;
        cout << count(s) << '\n';
        for (int i = 0; i <= s.length(); i++)
            suf[i] = 0, fac[i] = 0;
    }
}