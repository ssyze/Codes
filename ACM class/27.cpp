#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
string ans[maxn];
int t, n, m, Case;
struct node {
    int id, w, lson, rson;
    node(int _id = -1, int _w = -1, int _l = -1, int _r = -1)
    {
        id = _id, w = _w, lson = _l, rson = _r;
    }
    bool operator<(const node& a) const
    {
        if (w == a.w) return id < a.id;
        return w > a.w;
    }
} a[maxn];
void dfs(node u, string res)
{
    ans[u.id] = res;
    if (u.lson == -1 && u.rson == -1) return;
    if (u.lson != -1) dfs(a[u.lson], res + "0");
    if (u.rson != -1) dfs(a[u.rson], res + "1");
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        m = n;
        priority_queue<node> q;
        for (int i = 0; i < maxn; i++) a[i].lson = a[i].rson = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i].w;
            a[i].id = i;
            q.push(a[i]);
        }
        while (q.size() > 1) {
            node r = q.top();
            q.pop();
            node l = q.top();
            q.pop();
            node tmp(n, r.w + l.w, l.id, r.id);
            a[n++] = tmp;
            q.push(tmp);
        }
        dfs(q.top(), "");
        cout << "Case " << ++Case << endl;
        for (int i = 0; i < m; i++) cout << a[i].w << ' ' << ans[i] << endl;
        cout << endl;
    }
}