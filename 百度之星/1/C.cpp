/*
 * @Date         : 2020-07-19 14:27:28
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int t, a, b;
int prime[maxn] = {0}, vis[maxn] = {0}, tot;
void euler()
{
    vis[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            vis[i]++;
            for (int j = i + i; j < maxn; j += i) vis[j]++;
        }
        vis[i] = prime[tot - 1];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    euler();
    cin >> t;
    while (t--) {
        scanf("%d%d", &a, &b);
        int aa = vis[a];
        int bb = vis[b];
        int ans1 = 0, ans2 = 0;
        for (int i = a; i > aa; i--) {
            if (__gcd(i, b) == 1) ans1++;
        }
        ans1 += (b - 1);
        ans1 -= b / aa;
        ans1 += aa;
        for (int i = b; i > bb; i--) {
            if (__gcd(i, a) == 1) ans2++;
        }
        ans2 += (a - 1);
        ans2 -= a / bb;
        ans2 += bb;
        cout << ans1 << ' ' << ans2 << endl;
        printf("%d\n", max(ans1, ans2));
    }
}