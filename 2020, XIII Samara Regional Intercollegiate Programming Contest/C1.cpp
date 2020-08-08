/*
 * @Date         : 2020-05-22 18:47:35
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
#define lson pos << 1
#define rson pos << 1 | 1
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn << 2], n, k;
pair<int, int> p[maxn];
vector<int> y;
void pushup(int pos)
{
    a[pos] = a[lson] + a[rson];
}
void update(int k, int val, int L, int R, int pos)
{
    if (L == R) {
        a[pos] += val;
        return;
    }
    int mid = (L + R) >> 1;
    if (k <= mid)
        update(k, val, L, mid, lson);
    else
        update(k, val, mid + 1, R, rson);
    pushup(pos);
}
int query(int l, int r, int L, int R, int pos)
{
    if (l == 0 && r == 0)
        return 0;
    if (l <= L && r >= R)
        return a[pos];
    int mid = (L + R) >> 1;
    int res = 0;
    if (l <= mid)
        res += query(l, r, L, mid, lson);
    if (r > mid)
        res += query(l, r, mid + 1, R, rson);
    return res;
}
int check(int m)
{
    memset(a, 0, sizeof(a));
    long long sum = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < i && p[i].first - p[j].first > m) {
            //cout << "*** " << i << ' ' << j << ' ';
            update(lower_bound(y.begin(), y.end(), p[j].second) - y.begin() + 1, -1, 1, maxn, 1);
            j++;
        }
        //cout << m << ' ' << i << ' ' << p[i].first << ' ' << p[i].second << ' ';
        int pos1 = upper_bound(y.begin(), y.end(), p[i].second + m) - y.begin();
        int pos2 = lower_bound(y.begin(), y.end(), p[i].second - m) - y.begin() + 1;
        //cout << "pos1:" << pos1 << ' ' << "pos2:" << pos2 << ' ';
        sum += query(pos2, pos1, 1, maxn, 1);
        //cout << "res1" << ' ' << sum << ' ';
        int pos = lower_bound(y.begin(), y.end(), p[i].second) - y.begin() + 1;
        //cout << "pos:" << pos << endl;
        update(pos, 1, 1, maxn, 1);
    }
    //cout << sum << endl;
    return sum;
}
int main()
{
    //freopen("ans.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1;
        cin >> x1 >> y1;
        p[i].first = x1 + y1; //曼哈顿距离转切比雪夫距离
        p[i].second = x1 - y1;
        y.push_back(p[i].second); //扫描线垂直x轴
    }
    sort(p, p + n);
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    int L = 0, R = 5e8, ans = -1;
    while (L <= R) {
        int mid = L + R >> 1;
        if (check(mid) >= k) {
            ans = mid;
            R = mid - 1;
        }
        else
            L = mid + 1;
    }
    cout << ans << endl;
}