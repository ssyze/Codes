#include <bits/stdc++.h>
using namespace std;
int n, mn = 0x3f3f3f3f;
vector<int> a, b;
void dfs(int pos, vector<int> a, vector<int> b)
{
    if (pos == 7) {
        mn = min(mn, min(a[1], b[2]) + min(a[2], b[3]) + min(a[3], b[1]));
        return;
    }
    if (pos == 1 || pos == 4) {
        vector<int> c = a, d = b;
        c[1] -= min(a[1], b[1]);
        d[1] -= min(a[1], b[1]);
        if (c[1] > 0) {
            int tmp = c[1];
            c[1] -= min(tmp, b[3]);
            d[3] -= min(tmp, b[3]);
        }
        dfs(pos + 1, c, d);
        c = a, d = b;
        c[1] -= min(a[1], b[3]);
        d[3] -= min(a[1], b[3]);
        if (c[1] > 0) {
            int tmp = c[1];
            c[1] -= min(tmp, b[1]);
            b[1] -= min(tmp, b[1]);
        }
        dfs(pos + 1, c, d);
    }
    if (pos == 2 || pos == 5) {
        vector<int> c = a, d = b;
        c[2] -= min(a[2], b[2]);
        d[2] -= min(a[2], b[2]);
        if (c[2] > 0) {
            int tmp = c[2];
            c[2] -= min(tmp, b[1]);
            d[1] -= min(tmp, b[1]);
        }
        dfs(pos + 1, c, d);
        c = a, d = b;
        c[2] -= min(a[2], b[1]);
        d[1] -= min(a[2], b[1]);
        if (c[2] > 0) {
            int tmp = c[2];
            c[2] -= min(tmp, b[2]);
            b[2] -= min(tmp, b[2]);
        }
        dfs(pos + 1, c, d);
    }
    if (pos == 3 || pos == 6) {
        vector<int> c = a, d = b;
        c[3] -= min(a[3], b[3]);
        d[3] -= min(a[3], b[3]);
        if (c[3] > 0) {
            int tmp = c[3];
            c[3] -= min(tmp, b[2]);
            d[2] -= min(tmp, b[2]);
        }
        dfs(pos + 1, c, d);
        c = a, d = b;
        c[3] -= min(a[3], b[2]);
        d[2] -= min(a[3], b[2]);
        if (c[3] > 0) {
            int tmp = c[3];
            c[3] -= min(tmp, b[3]);
            b[3] -= min(tmp, b[3]);
        }
        dfs(pos + 1, c, d);
    }
}
int main()
{
    cin >> n;
    a.resize(4), b.resize(4);
    cin >> a[1] >> a[2] >> a[3];
    cin >> b[1] >> b[2] >> b[3];
    int mx = min(a[1], b[2]) + min(a[2], b[3]) + min(a[3], b[1]);
    dfs(1, a, b);
    cout << mn << ' ' << mx << endl;
}