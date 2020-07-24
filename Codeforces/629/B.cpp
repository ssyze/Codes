/*
 * @Date         : 2020-03-29 14:21:29
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char a[maxn];
int t, n, k;
long long sum(long long n)
{
    return (n + 1) * n / 2;
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            a[i] = 'a';
        long long tmp = 0;
        while (sum(tmp) < k) {
            //cout << sum(tmp) << endl;
            tmp++;
        }
        long long rest = k - sum(tmp - 1) - 1;
        //cout << tmp << ' ' << rest << endl;
        a[n - tmp - 1] = 'b';
        a[n - rest - 1] = 'b';
        printf("%s\n", a);
        for (int i = 0; i < n; i++)
            a[i] = '\0';
    }
}