/*
 * @Date         : 2020-02-06 13:01:48
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, x, y, z, ans;
int main()
{
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    ans = min(a, y) + min(b, z) + min(c, x);
    cout << ans << endl;
}