/*
 * @Date         : 2020-05-22 13:05:19
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, ans[maxn];
int main()
{
    cin >> n;
    int num = n / 2 + 1;
    cout << num << endl;
    for (int i = 1; i <= n; i += 2)
        cout << i << ' ';
    if (!(n & 1))
        cout << n;
    cout << endl;
}