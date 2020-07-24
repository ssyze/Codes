/*
 * @Date         : 2020-05-23 13:59:04
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a;
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b;
    if (n > m)
        cout << "Cuber QQ" << endl;
    else
        cout << "Quber CC" << endl;
}