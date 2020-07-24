/*
 * @Date         : 2020-02-04 13:07:08
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            cout << i << endl;
            return 0;
        }
    }
}