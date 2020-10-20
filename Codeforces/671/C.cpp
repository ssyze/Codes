#include <bits/stdc++.h>
using namespace std;
const int maxn = 4005;
int t, n, x;
int a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int flag = 1, sum = 0, flag1 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] != x) flag = 0;
            if (a[i] == x) flag1 = 1;
            sum += (a[i] - x);
        }
        if (flag)
            cout << 0 << '\n';
        else if (sum == 0 || flag1)
            cout << "1\n";
        else
            cout << "2\n";
    }
}