#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int a[maxn];
int n;
int main()
{
    cin >> n;
    int ans = 1, sum = 0;
    while (1) {
        sum += ans;
        if (sum > n) {
            sum -= ans;
            ans--;
            break;
        }
        a[ans] = ans;
        ans++;
    }
    int tmp = n - sum;
    for (int i = ans - tmp + 1; i <= ans; i++)
        a[i]++;
    cout << ans << endl;
    for (int i = 1; i <= ans; i++)
        cout << a[i] << ' ';
    cout << endl;
}