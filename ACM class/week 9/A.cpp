/*
 * @Date         : 2020-03-18 16:21:52
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int a[35], vis[35];
int n, cnt;
vector<int> v[35];
void dfs(int x)
{
    vis[x] = 1;
    v[cnt].push_back(x);
    //cout << x << endl;
    if (!vis[a[x]]) {
        dfs(a[x]);
    }
    else {
        cnt++;
        return;
    }
}
int main()
{
    while (cin >> n) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i])
                dfs(i);
        }
        for (int i = 0; i < cnt; i++) {
            cout << '(';
            for (int j = 0; j < v[i].size() - 1; j++) {
                cout << v[i][j] << ' ';
            }
            cout << v[i][v[i].size() - 1] << ')';
        }
        cout << endl;
        for (int i = 0; i < cnt; i++)
            v[i].clear();
    }
}