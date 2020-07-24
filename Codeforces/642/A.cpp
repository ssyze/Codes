/*
 * @Date         : 2020-05-14 22:34:34
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
long long t, n, m;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n == 1)
            cout << 0 << endl;
        else if (n == 2)
            cout << m << endl;
        else
            cout << m * 2 << endl;
    }
}