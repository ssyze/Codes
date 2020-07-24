/*
 * @Date         : 2020-07-18 12:18:41
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 100;

string s;
int t, n, ans, clam, nothing, fish, suf[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        fish = 0;
        clam = 0;
        nothing = 0;
        cin >> n;
        cin >> s;
        for (int i = n - 1; i >= 0; --i) {
            int cur = s[i] - '0';
            if (i == n - 1)
                suf[i] = 0;
            else
                suf[i] = suf[i + 1];
            if (cur < 2) suf[i]++;
        }
        for (int i = 0; i < n; ++i) {
            int cur = s[i] - '0';
            if (cur >= 2)
                fish++;
            else if (clam >= suf[i])
                fish++, clam--;
            else {
                if (cur == 1) clam++;
                if (cur == 0 && clam > 0) clam--, fish++;
            }
        }
        cout << fish << '\n';
    }
}