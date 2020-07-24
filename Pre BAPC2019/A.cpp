/*
 * @Date         : 2020-03-14 13:03:46
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int R, C, r[maxn], c[maxn], mxr, mxc;
int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> r[i], mxr = max(mxr, r[i]);
    for (int i = 0; i < C; i++)
        cin >> c[i], mxc = max(mxc, c[i]);
    if (mxr == mxc)
        cout << "possible" << endl;
    else
        cout << "impossible" << endl;
}