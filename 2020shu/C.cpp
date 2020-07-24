/*
 * @Date         : 2020-04-18 12:15:22
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
string a, b;
int main()
{
    cin >> a >> b;
    if (a == b)
        cout << -1 << endl;
    else
        cout << max(a.length(), b.length()) << endl;
}