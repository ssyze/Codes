/*
 * @Date         : 2020-04-18 11:59:27
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    cout << abs(a[0] + a[3] - a[1] - a[2]) << endl;
}