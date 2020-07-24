/*
 * @Date         : 2020-02-06 13:05:40
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, num1, num6;
string s;
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            num1++;
        if (s[i] == '6')
            num6++;
    }
    //cout << num1 << ' ' << num6 << endl;
    if (num6 <= 1 || num1 == 0)
        cout << 0 << endl;
    else if (num1 < num6)
        cout << num1 << endl;
    else
        cout << num6 - 1 << endl;
}