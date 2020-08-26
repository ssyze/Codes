#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int base = 131;
ll h1[maxn], h2[maxn], f[maxn];
int Case;
string s;
void get_h()
{
    for (int i = 1; i <= s.length(); i++) h1[i] = (h1[i - 1] * base + s[i - 1] - 'a');
    for (int i = s.length(); i >= 1; i--) h2[i] = (h2[i + 1] * base + s[i - 1] - 'a');
}
bool check(int l1, int r1, int l2, int r2)
{
    ll ha1 = h1[r1] - h1[l1 - 1] * f[r1 - l1 + 1];
    ll ha2 = h2[l2] - h2[r2 + 1] * f[r2 - l2 + 1];
    return ha1 == ha2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = f[i - 1] * base;
    while (cin >> s) {
        if (s == "END") break;
        get_h();
        int ans = -1, len = s.length();
        for (int i = 1; i <= s.length(); i++) {
            int l = 1, r = min(i - 1, len - i), ans1 = 0; // 奇数
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (check(i - mid, i - 1, i + 1, i + mid))
                    l = mid + 1, ans1 = mid;
                else
                    r = mid - 1;
            }
            ans = max(ans, 2 * ans1 + 1);
            l = 1, r = min(i, len - i), ans1 = 0; // 偶数
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (check(i - mid + 1, i, i + 1, i + mid))
                    l = mid + 1, ans1 = mid;
                else
                    r = mid - 1;
            }
            ans = max(ans, 2 * ans1);
        }
        cout << "Case " << ++Case << ": " << ans << endl;
    }
    return 0;
}