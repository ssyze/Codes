/*
 * @Date         : 2019-12-28 13:19:38
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 27;
int n, ans1;
string s;
char ans[maxn];
bool vis[maxn];
int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (!vis[s[i] - 'a']) {
            ans[ans1++] = s[i];
            vis[s[i] - 'a'] = 1;
        }
    }
    ans[ans1] = '\0';
    printf("%d\n%s\n", ans1, ans);
}