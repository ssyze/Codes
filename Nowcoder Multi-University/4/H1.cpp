/*
 * @Date         : 2020-07-20 22:21:12
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, prime[maxn], vis[maxn], bg[maxn], tot, ansn;
vector<int> num[50000];
map<int, int> mp;
vector<pair<int, int>> ans;
void init()
{
    for (int i = 2; i < maxn; i++) bg[i] = i;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[++tot] = i;
            for (int j = i; j < maxn; j += i) {
                vis[j] = 1;
                while (bg[j] % i == 0) bg[j] /= i;
                if (bg[j] == 1) bg[j] *= i;
            }
        }
    }
    for (int i = 1; i <= tot; i++) mp[prime[i]] = i;
}
int main()
{
    init();
    scanf("%d", &t);
    while (t--) {
        ansn = 0;
        ans.clear();
        scanf("%d", &n);
        for (int i = 2; i <= n; i++) num[mp[bg[i]]].push_back(i);
        for (int i = tot; i >= 2; i--) {
            if (num[i].size() <= 1) continue;
            if (num[i].size() % 2 == 1) {
                num[1].push_back(num[i][1]);
                ans.push_back({num[i][0], num[i][2]});
                for (int j = 3; j < num[i].size() - 1; j += 2) {
                    ans.push_back({num[i][j], num[i][j + 1]});
                }
                continue;
            }
            for (int j = 0; j < num[i].size() - 1; j += 2)
                ans.push_back({num[i][j], num[i][j + 1]});
        }
        for (int i = 0; i < num[1].size() - 1; i += 2)
            ans.push_back({num[1][i], num[1][i + 1]});
        printf("%d\n", ans.size());
        for (auto& x : ans) printf("%d %d\n", x.first, x.second);
        for (int i = 1; i < 50000; i++) num[i].clear();
    }
}