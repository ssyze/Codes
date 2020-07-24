/*
 * @Date         : 2020-01-05 16:01:45
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int f[maxn], s[maxn];
int n;
int main()
{
    vector<int> a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        s[f[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!f[i])
            a.push_back(i);
        if (!s[i])
            b.push_back(i);
    }
    for (int i = 0; i < a.size(); i++)
        if (a[i] == b[i])
            swap(b[i], b[(i + 1) % b.size()]);
    for (int i = 0; i < a.size(); i++)
        f[a[i]] = b[i];
    for (int i = 1; i <= n; i++)
        cout << f[i] << ' ';
    cout << endl;
}