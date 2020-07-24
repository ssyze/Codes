/*
 * @Date         : 2020-04-28 14:46:55
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n & 1)
            cout << n / 2 << endl;
        else
            cout << n / 2 - 1 << endl;
    }
}