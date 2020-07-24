/*
 * @Date         : 2020-06-13 15:43:12
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int sum[maxn], q;
int main()
{
    for (int i = 1; i < maxn; i++)
        for (int j = i; j < maxn; j += i)
            sum[j] += i;
    for (int i = 1; i < maxn; i++)
        sum[i] += sum[i - 1];
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
}