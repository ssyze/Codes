/*
 * @Date         : 2020-08-13 14:45:27
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve(int n)
{
    if (n <= 1) return;
    if (n == 2) {
        cout << "345613";
        return;
    }

    cout << "3";
    for (int i = 0; i < n - 2; i++) cout << "42";
    cout << "4";
    for (int i = 0; i < n - 2; i++) cout << "53";
    cout << "5";
    for (int i = 0; i < n - 2; i++) cout << "64";
    cout << "6";
    for (int i = 0; i < n - 2; i++) cout << "15";
    cout << "1";
    for (int i = 0; i < n - 2; i++) cout << "26";
    cout << "2";
    for (int i = 0; i < n - 3; i++) cout << "31";
    cout << "34";

    solve(n - 2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
        cout << '\n';
    }
}