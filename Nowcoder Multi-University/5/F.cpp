/*
 * @Date         : 2020-07-25 12:13:18
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 105;
int n, d[maxn], mx = -1, l[maxn], flag[maxn];
void Output(int x)
{
    cout << "+";
    for (int i = 0; i < l[x]; i++) cout << "-";
    cout << "+" << '\n';
    cout << "|";
    for (int i = 0; i < l[x]; i++) {
        if (i == l[x] - 1 && flag[x])
            cout << "*";
        else
            cout << " ";
    }
    cout << "|" << d[x] << '\n';
    cout << "+";
    for (int i = 0; i < l[x]; i++) cout << "-";
    cout << "+" << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        mx = max(mx, d[i]);
    }
    for (int i = 0; i < n; i++) {
        l[i] = ceil(double(d[i]) / double(mx) * 50.0 - eps);
        if (mx == d[i]) flag[i] = 1;
    }
    for (int i = 0; i < n; i++) Output(i);
}