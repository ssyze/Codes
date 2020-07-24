/*
 * @Date         : 2020-02-11 13:29:19
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
char l[maxn];
char s[maxn];
int t, n;
int solve()
{
    //cout << s << endl;
    int ans = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        //cout << s[i] << ' ' << ans << ' ' << idx << endl;
        if (s[i] == '(') {
            l[idx++] = s[i];
        }
        else {
            if (idx == 0) {
                ans++;
                continue;
            }
            else if ((s[i] == ')' && l[idx - 1] != '('))
                ans++;
            idx--;
        }
    }
    //cout << ans << ' ' << idx << endl;
    if (idx == 0)
        return ans;
    else
        return ans + idx;
}
int main()
{
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        scanf("%s", s);
        cout << solve() << endl;
        s[0] = '\0';
        l[0] = '\0';
    }
}