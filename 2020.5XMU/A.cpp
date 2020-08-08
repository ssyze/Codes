/*
 * @Date         : 2020-05-17 13:07:23
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, a[maxn];
map<int, int> num;
int main()
{
    cin >> n;
    int cnt = 0, flag = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (num[x] == 0) {
            cnt++;
            num[x] = cnt;
        }
        a[i] = num[x];
    }
    for (int i = 1; i <= n / 2; i++) {
        cout << a[i] << endl;
        if (a[i] <= a[i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << "chong" << endl;
    else
        cout << "fuchong" << endl;
}