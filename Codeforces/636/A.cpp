/*
 * @Date         : 2020-06-14 16:27:09
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int tmp = 4;
        for (;;) {
            if (n / (tmp - 1) * (tmp - 1) == n)
                break;
            tmp *= 2;
        }
        cout << n / (tmp - 1) << endl;
    }
}