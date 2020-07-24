/*
 * @Date         : 2020-02-12 15:42:36
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, dep[maxn];
long long o, e;
vector<int> g[maxn];
void dfs(int cur, int fa)
{
    dep[cur] = dep[fa] + 1;
    if (dep[cur] & 1)
        o++;
    else
        e++;
    for (auto& x : g[cur]) {
        if (x == fa)
            continue;
        else
            dfs(x, cur);
    }
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int fa;
        scanf("%d", &fa);
        g[i].push_back(fa);
        g[fa].push_back(i);
    }
    dfs(1, 0);
    cout << o * (o - 1) + e * (e - 1) << endl;
}