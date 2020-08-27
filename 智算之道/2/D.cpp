/*
 * @Date         : 2020-08-09 17:42:08
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll, ll> p[50005];
int main()
{
    long long n, b;
    unsigned int a;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) p[i].first = 1, p[i].second = i;
    for (int i = 1; i <= n; i++) {
        if (p[i].second == 1) continue;
        ll q = p[i].second;
        for (int j = i + 1; j <= n; j++) {
            p[j].first *= q;
            ll tmp = __gcd(p[j].first, p[j].second);
            p[j].first /= tmp;
            p[j].second /= tmp;
        }
        a = a * q + b;
    }
    cout << a << endl;
}