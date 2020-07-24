/*
 * @Date         : 2020-03-20 17:17:37
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u, v;
int main()
{
    cin >> u >> v;
    if (u > v || (v - u) & 1)
        cout << -1 << endl;
    else {
        if (u == v && u == 0)
            cout << 0 << endl;
        else if (u == v)
            cout << "1\n"
                 << u << endl;
        else {
            ll x = (v - u) / 2;
            if ((u ^ x) + x == v)
                cout << "2\n"
                     << (u ^ x) << ' ' << x << endl;
            else
                cout << "3\n"
                     << u << ' ' << x << ' ' << x << endl;
        }
    }
}