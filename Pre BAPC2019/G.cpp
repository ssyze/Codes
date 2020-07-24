/*
 * @Date         : 2020-03-14 12:34:57
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int cnt;
string s;
int main()
{
    cin >> s;
    int cnt = 2 * (s.length() - 2);
    cout << 'h';
    for (int i = 0; i < cnt; i++)
        cout << 'e';
    cout << 'y' << endl;
}