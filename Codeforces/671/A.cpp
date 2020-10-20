#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        if (n & 1) {
            int flag = 0;
            for (int i = 0; i < s.length(); i += 2) {
                if ((s[i] - '0') & 1) flag = 1;
            }
            if (flag)
                cout << "1\n";
            else
                cout << "2\n";
        } else {
            int flag = 0;
            for (int i = 1; i < s.length(); i += 2) {
                if ((s[i] - '0') % 2 == 0) flag = 1;
            }
            if (flag)
                cout << "2\n";
            else
                cout << "1\n";
        }
    }
}