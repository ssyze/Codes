/*
 * @Date         : 2020-05-22 15:19:54
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
struct edge {
    int from, to;
    char al;
    int l[maxn];
};

vector<edge> g[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        g[a].push_back({ b, c });
        g[b].push_back({ a, c });
    }
}