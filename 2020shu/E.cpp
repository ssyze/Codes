/*
 * @Date         : 2020-04-18 12:12:06
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll n, a[maxn], sum;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum - (n - 1) * n / 2 << endl;
}