/*
 * @Date         : 2020-06-16 19:40:35
 * @Author       : ssyze
 * @Description  :  
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
string s[maxn];
int n, a[maxn], mx[maxn], mn[maxn];
int main()
{
    //freopen("t.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> a[i];
        a[i] *= 100;
        mx[i] = a[i] + 49;
        mn[i] = a[i] - 50;
        if (a[i] == 10000)
            mx[i] -= 49;
        if (a[i] == 0)
            mn[i] = 0;
    }
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n; i++)
        sum1 += mx[i], sum2 += a[i], sum3 += mn[i];
    if (sum1 < 10000 || sum3 > 10000) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int tmp = sum1 - mx[i];
        //cout << tmp << endl;
        tmp = 10000 - tmp;
        if (a[i] != 0) {
            if (a[i] - tmp > 50)
                mn[i] = a[i] - 50;
            else
                mn[i] = tmp;
        } else {
            if (-tmp > 0)
                mn[i] = 0;
            else
                mn[i] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        int tmp = sum3 - mn[i];
        tmp = 10000 - tmp;
        if (a[i] != 10000) {
            if (a[i] - tmp < -49)
                mx[i] = a[i] + 49;
            else
                mx[i] = tmp;
        } else {
            if (tmp >= 10000)
                mx[i] = 10000;
            else
                mx[i] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << ' ';
        //cout << mx[i] << ' ' << mn[i] << endl;
        double mxx = double(mx[i]) / 100.0;
        double mnn = double(mn[i]) / 100.0;
        printf("%.2f %.2f\n", mnn, mxx);
    }
}