/*
 * @Date         : 2020-01-05 15:15:32
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    cin >> t;
    while (t--) {
        int h, m;
        cin >> h >> m;
        cout << (23 - h) * 60 + 60 - m << endl;
    }
}