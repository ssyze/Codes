/*
 * @Date         : 2020-05-22 17:53:26
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
#include <random>
#define ll long long
#define mp make_pair
#define SIZE 100010
using namespace std;
ll n, k;

namespace FenwickTree {
int t[SIZE];

int lowbit(int x) { return x & (-x); }

void add(int pos, int x, int t[])
{ // 单点修改
    for (; pos <= n; pos += lowbit(pos)) {
        t[pos] += x;
    }
}

int query_presum(int pos, int t[])
{ // 单点查询
    int ans = 0;
    for (; pos > 0; pos -= lowbit(pos)) {
        ans += t[pos];
    }
    return ans;
}
}
using namespace FenwickTree;

ll check(int d, vector<pair<int, int>>& p, vector<int>& y)
{
    ll res = 0;
    memset(t, 0, sizeof(t));
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < i && p[i].first - p[j].first > d) {
            //cout << "*** " << i << ' ' << j << ' ';
            add(lower_bound(y.begin(), y.end(), p[j].second) - y.begin() + 1, -1, t);
            j++;
        }
        //cout << d << ' ' << i << ' ' << p[i].first << ' ' << p[i].second << ' ';
        //cout << "pos1:" << upper_bound(y.begin(), y.end(), p[i].second + d) - y.begin() << ' ';
        res += query_presum(upper_bound(y.begin(), y.end(), p[i].second + d) - y.begin(), t);
        //cout << "res1" << ' ' << res << ' ';
        res -= query_presum(lower_bound(y.begin(), y.end(), p[i].second - d) - y.begin(), t);
        //cout << "pos2:" << lower_bound(y.begin(), y.end(), p[i].second - d) - y.begin() << ' ';
        //cout << "res2" << ' ' << res << endl;
        add(lower_bound(y.begin(), y.end(), p[i].second) - y.begin() + 1, 1, t);
    }
    return res;
}

int main()
{
    //freopen("ans1,txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    vector<int> y;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        p[i].first = a + b;
        p[i].second = a - b;
        y.emplace_back(p[i].second);
    }
    sort(p.begin(), p.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    int L = 0, R = 4e8, mid;
    while (R > L) {
        mid = (L + R) >> 1;
        if (check(mid, p, y) < k)
            L = mid + 1;
        else
            R = mid;
    }
    cout << L;
}