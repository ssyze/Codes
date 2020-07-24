#include <bits/stdc++.h>
using namespace std;
int t, n, ansl, ansr;
string s;
bool check(int a)
{
    for (int i = 0; i < n - a; i++) {
        int L = 0, R = 0, U = 0, D = 0;
        for (int j = 0; j < a; j++) {
            if (s[i + j] == 'L')
                L++;
            else if (s[i + j] == 'R')
                R++;
            else if (s[i + j] == 'U')
                U++;
            else if (s[i + j] == 'D')
                D++;
        }
        if (L == R && U == D && (L || U)) {
            ansl = i + 1, ansr = ansl + a - 1;
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int l = 0, r = n;
        ansl = -1, ansr = -1;
        while (l < r) {
            cout << l << ' ' << r << endl;
            int mid = (l + r) / 2;
            /* if (mid & 1)
                mid--; */
            if (check(mid)) {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (ansl == -1 && ansr == -1)
            cout << -1 << endl;
        else
            cout << ansl << ' ' << ansr << endl;
    }
}