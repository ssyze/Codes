/*
 * @Date         : 2020-05-14 22:57:11
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n;
int ans[maxn];
struct D {
    int l, r, len;
    bool operator<(const D x) const
    {
        if (len == x.len)
            return l > x.l;
        else
            return len < x.len;
    }
};

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<D> q;
        q.push(D { 1, n, n });
        int ti = 0;
        while (!q.empty()) {
            auto x = q.top();
            q.pop();
            int mid = (x.l + x.r) / 2;
            ans[mid] = ++ti;
            if ((mid - 1) >= x.l)
                q.push(D { x.l, mid - 1, mid - x.l });
            if ((mid + 1) <= x.r)
                q.push(D { mid + 1, x.r, x.r - mid });
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}