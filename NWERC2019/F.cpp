#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
map<int, int> mp;
vector<int> v[maxn], a[maxn];
map<int, int> h;
int cnt, fa[maxn];
int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void uni(int a, int b)
{
    int f1 = find(a), f2 = find(b);
    fa[f2] = f1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0, x; j < m; j++) {
            cin >> x;
            a[i].push_back(x);
            if (mp.find(x) == mp.end()) h[x] = ++cnt;
            mp[x]++;
            v[h[x]].push_back(i);
        }
    }
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        int cnt1 = 0;
        for (auto& x : a[i]) {
            if (mp[x] == 1) cnt1++;
        }
        if (cnt1 == a[i].size()) flag = 0;
    }
    if (!flag) {
        cout << "impossible" << '\n';
        return 0;
    }
    for (auto& x : h) {
        int tmp = x.first, tp = x.second;
        int s = v[tp][0];
        for (int i = 1; i < v[tp].size(); i++) {
            if (find(s) != find(v[tp][i])) {
                cout << s << ' ' << v[tp][i] << ' ' << tmp << '\n';
                uni(s, v[tp][i]);
            }
        }
    }
}