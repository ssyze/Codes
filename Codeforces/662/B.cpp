/*
 * @Date         : 2020-08-07 22:49:40
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int n, a[maxn], eight, six, four, two;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i < maxn; i++) {
        if (a[i] >= 8)
            eight++;
        else if (a[i] >= 6)
            six++;
        else if (a[i] >= 4)
            four++;
        else if (a[i] >= 2)
            two++;
    }
    int q;
    cin >> q;
    while (q--) {
        char al;
        int x;
        cin >> al >> x;
        if (al == '+') {
            a[x]++;
            if (a[x] == 8)
                eight++, six--;
            else if (a[x] == 6)
                six++, four--;
            else if (a[x] == 4)
                four++, two--;
            else if (a[x] == 2)
                two++;
        }
        else {
            a[x]--;
            if (a[x] == 7)
                eight--, six++;
            else if (a[x] == 5)
                six--, four++;
            else if (a[x] == 3)
                four--, two++;
            else if (a[x] == 1)
                two--;
        }
        if (eight || (six >= 2) || (six && two) || (six && four) || (four >= 2) ||
            (four && two >= 2))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
