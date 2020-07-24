/*
 * @Date         : 2020-04-18 12:26:30
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    if (n == 1)
        cout << "1\n1" << endl;
    else if (n == 2) {
        cout << "2\n0\n11" << endl;
    }
    else {
        cout << n - 1 << endl;
        for (int i = 2; i <= n; i++) {
            cout << 1;
            for (int j = 0; j < i - 2; j++) {
                cout << 0;
            }
            cout << 1 << endl;
        }
    }
}