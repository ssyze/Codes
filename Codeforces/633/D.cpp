/*
 * @Date         : 2020-04-21 16:20:33
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> g[maxn];
int n, dep[maxn], in[maxn], son[maxn];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    for (auto& x : g[u]) {
        if (x == fa)
            continue;
        dfs(x, u);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        in[a]++, in[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 1)
            son[g[i][0]]++;
    }
    dfs(1, 0);
    int ans = 0, odd = 0, even = 0;
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 1) {
            if (dep[i] & 1)
                odd++;
            else
                even++;
            if (son[g[i][0]] == 1)
                ans++;
            else
                m[g[i][0]] = 1;
        }
        else
            ans++;
    }
    ans += m.size();
    printf("%d %d\n", odd && even ? 3 : 1, ans - 1);
}