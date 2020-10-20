#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int a[5];

int main()
{

    for (int i = 0; i < 5; i++) {
        double num;
        cin >> num;
        a[i] = num * 100;
        // if (a[i] % 10) a[i]++;
        // cout << a[i] << '\n';
    }
    sort(a, a + 4);
    if (a[1] + a[2] + a[3] <= a[4] * 3)
        cout << "infinite" << '\n';
    else if (a[0] + a[1] + a[2] > a[4] * 3)
        cout << "impossible" << '\n';
    else {
        int t = a[4] * 3 - a[1] - a[2];
        double ans = t / 100.0;
        cout << setprecision(2) << fixed << ans << '\n';
    }
    return 0;
}
