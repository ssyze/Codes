/*
 * @Date         : 2020-08-03 14:21:52
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("I.in", "w", stdout);
    cout << "10" << endl;
    for (int i = 0; i < 9; i++) {
        cout << 100000 << endl;
        for (int j = 0; j < 100000; j++) {
            cout << 1000000000 << ' ';
        }
        cout << endl;
        for (int j = 100000; j >= 1; j--) {
            cout << 100000 << ' ';
        }
        cout << endl;
    }
}