/*
 * @Date         : 2020-03-20 15:42:29
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (x & 1)
            cout << 1 << ' ' << x - 1 << endl;
        else
            cout << x / 2 << ' ' << x / 2 << endl;
    }
}