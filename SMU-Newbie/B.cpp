#include <bits/stdc++.h>
using namespace std;
bool vis[128];
int n, num;
string s;
int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (!vis[s[i]]) {
            num++;
            vis[s[i]] = 1;
        }
    }
    int l = 0, t = 0, a[1000], sum = 0, ans = 0x3f3f3f3f;
    memset(a, 0, sizeof(a));
    for (int i = 0; s[i]; i++) {
        if (a[s[i]] == 0)
            t++;
        a[s[i]]++;
        while (t == num) {
            ans = min(ans, i - l + 1);
            a[s[l]]--;
            if (a[s[l]] == 0)
                t--;
            l++;
        }
    }
    cout << ans << endl;
}