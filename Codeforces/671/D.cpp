#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], b[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(b, -1, sizeof(b));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int tmp = n / 2, ans = 0;
    for (int i = 0; i < n; i += 2) b[i] = a[tmp++];
    for (int i = 1, cnt = 0; i < n; i += 2) b[i] = a[cnt++];
    for (int i = 1; i < n; i += 2) {
        if (b[i] < b[i - 1] && b[i] < b[i + 1]) ans++;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << '\n';
}