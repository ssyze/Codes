#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, m, d, w;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> m >> d >> w;
        w /= __gcd(d - 1, w);
        ll mn = min(m, d) - 1;
        ll x = mn / w, y = mn % w + 1;
        cout << x * (x - 1) * w / 2 + x * y << '\n';
    }
}