#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int pnum, inum, znum, ans, n;
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            inum++;
            ans += (-1 - x);
        } else if (x > 0) {
            pnum++;
            ans += (x - 1);
        } else {
            znum++;
        }
    }
    if ((inum & 1) && znum)
        ans += znum;
    else {
        ans += znum;
        if (inum & 1)
            ans += 2;
    }
    cout << ans << endl;
}