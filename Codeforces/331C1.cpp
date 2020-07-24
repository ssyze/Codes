/*
 * @Date         : 2019-12-19 23:04:36
 * @Author       : ssyze
 * @Description  : C3 1e18数据量 数位DP 以后再补
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int Get(int x)
{
    int ans = 0;
    while (x) {
        ans = max(ans, x % 10);
        x /= 10;
    }
    return ans;
}
int main()
{
    cin >> n;
    int step = 0;
    while (n) {
        int tmp = Get(n);
        step++;
        n -= tmp;
    }
    cout << step << endl;
}