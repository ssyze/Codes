/*
 * @Date         : 2020-03-04 16:12:13
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int fa[maxn], d[maxn], n, m;
void init()
{
    memset(d, 0, sizeof(d));
    for (int i = 0; i <= n; i++)
        fa[i] = i;
}
int f(int i)
{
    if (fa[i] == i)
        return i;
    else
        return fa[i] = f(fa[i]);
}
int main()
{
    while (cin >> n >> m) {
        init();
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            d[u]++;
            d[v]++;
            u = f(u);
            v = f(v);
            if (u != v)
                fa[u] = v;
        }
        int ans = 0, flag = 0;
        for (int i = 1; i <= n; i++) {
            if (f(i) == i)
                ans++;
            if (d[i] & 1)
                flag = 1;
        }
        if (ans > 1 || flag)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
}