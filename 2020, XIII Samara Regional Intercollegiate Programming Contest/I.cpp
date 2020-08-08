/*
 * @Date         : 2020-05-22 13:12:18
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, num[maxn];
bool vis[maxn];
pair<int, int> p[maxn];
int main()
{
    cin >> n;
    int flag = 1;
    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        if (!vis[c])
            vis[c] = 1, num[c] = a;
        else {
            if (num[c] > a)
                flag = 0;
            num[c] = max(num[c], a);
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}