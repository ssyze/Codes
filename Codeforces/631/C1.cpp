/*
 * @Date         : 2020-04-16 16:48:41
 * @Author       : ssyze
 * @Description  : 
 */
/*
 * @Date         : 2020-04-16 15:24:49
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll n, m, sum, l[maxn], p[maxn], mx;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i];
        sum += l[i];
        //cout << sum << endl;
    }
    sum = sum - n;
    if (sum < 0) {
        cout << -1 << endl;
        return 0;
    }
    p[1] = 1;
    mx = max(mx, p[1] + l[1] - 1);
    for (int i = 2; i <= m; i++) {
        if (sum) {
            if (sum >= l[i])
                p[i] = p[i - 1] + 1;
            else {
                p[i] = mx - sum + 1;
                if (p[i] <= p[i - 1])
                    p[i] = p[i - 1] + 1;
            }
            //cout << p[i] << ' ' << sum << endl;
            int lst = p[i] + l[i] - 1;
            if (lst >= mx) {
                sum = sum - (mx - p[i] + 1);
                mx = lst;
            }
            else
                sum = sum - l[i];
        }
        else {
            p[i] = mx + 1;
            mx = p[i] + l[i] - 1;
        }
    }
    if (mx != n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= m; i++)
        cout << p[i] << ' ';
    cout << endl;
}