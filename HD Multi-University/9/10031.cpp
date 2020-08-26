#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 100;
const double eps = 1e-5;
int t;
double a, b, k, r, c;

int main()
{
    cin >> t;
    while (t--) {
        cin >> a >> b >> k;
        if (a > b) swap(a, b);
        r = sqrt((k + 1) * (k + 1) + 4) + 1 - k;
        r /= 2.0 * (k + 1);
        printf("%.10f\n", r);
        c = double(b - a);
        printf("%.10f\n", r * c);
        if (floor(r * c + eps) == a)
            cout << "0\n";
        else
            cout << "1\n";
    }
}
