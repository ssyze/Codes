/*
 * @Date         : 2020-03-24 14:14:27
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n, k, t;
long long a[maxn];
int main()
{
    int i = 1;
    for (int j = 1; a[i - 1] <= 1e7 + 5; j += 2, i++) {
        a[i] = a[i - 1] + j;
        //cout << a[i] << endl;
    }
    //cout << a[3163] << endl;
    //cout << i << endl;
    cin >> t;
    while (t--) {
        //cout << t << endl;
        cin >> n >> k;
        if (n & 1) {
            if (k % 2 == 0) {
                cout << "NO" << endl;
                continue;
            }
        }
        else {
            if (k & 1) {
                cout << "NO" << endl;
                continue;
            }
        }
        int pos = upper_bound(a, a + 3164, n) - a - 1;
        //cout << pos << endl;
        if (k > pos)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}