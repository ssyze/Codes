/*
 * @Date         : 2020-06-13 15:51:26
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, a[maxn];
vector<int> num(5);
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    cout << a[0] << endl;
}