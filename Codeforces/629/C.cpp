/*
 * @Date         : 2020-03-29 15:07:45
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
char a[2][maxn];
int t, n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        a[0][0] = '1';
        a[1][0] = '1';
        int big = 0, flag = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                a[big][i] = '1';
                a[!big][i] = '0';
                if (!flag) {
                    big = !big;
                    flag = 1;
                }
            }
            if (s[i] == '2') {
                if (flag) {
                    a[big][i] = '2';
                    a[!big][i] = '0';
                }
                else {
                    a[0][i] = '1';
                    a[1][i] = '1';
                }
            }
            if (s[i] == '0') {
                a[0][i] = '0';
                a[1][i] = '0';
            }
        }
        printf("%s\n%s\n", a[0], a[1]);
        for (int i = 0; i < n; i++) {
            a[0][i] = '\0';
            a[1][i] = '\0';
        }
    }
}