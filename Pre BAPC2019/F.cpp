/*
 * @Date         : 2020-03-14 13:49:42
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n & 1)
        cout << (n + 1) / 2 << ' ' << (n - 1) / 2 << endl;
    else if (n % 4 == 0)
        cout << (n / 4) + 1 << ' ' << (n / 4) - 1 << endl;
    else
        cout << "impossible" << endl;
}