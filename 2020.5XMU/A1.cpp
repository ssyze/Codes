/*
 * @Date         : 2020-05-17 13:43:32
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, a[maxn];
int main()
{
    cin >> n;
    int flag = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << "chong" << endl;
    else
        cout << "fuchong" << endl;
}