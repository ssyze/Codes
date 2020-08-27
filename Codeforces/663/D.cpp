/*
 * @Date         : 2020-08-09 23:26:36
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> g;
string num[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
string num1[] = {"00", "01", "10", "11"};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if (n >= 4 && m >= 4) {
        for (int i = 0, x; i < n; i++)
            for (int j = 0; j < m; j++) cin >> x;
        cout << -1 << '\n';
        return 0;
    }
    if (n == 1 || m == 1) {
        for (int i = 0, x; i < n; i++)
            for (int j = 0; j < m; j++) cin >> x;
        cout << 0 << '\n';
        return 0;
    }
    if (n == 3 || m == 3) {
        int ans = 0;
        g.resize(n);
        for (int i = 0; i < n; i++) {
            g[i].resize(m);
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }
        if (n == 3) {
            char tmp[4], now[4];
            tmp[0] = g[0][0], tmp[1] = g[1][0], tmp[2] = g[2][0];
            int pre = lower_bound(num, num + 8, tmp) - num, n1, n2;
            for (int i = 1; i < m; i++) {
                now[0] = g[0][i], now[1] = g[1][i], now[2] = g[2][i];
                if (pre == 0) n1 = 2, n2 = 5;
                if (pre == 1) n1 = 4, n2 = 3;
                if (pre == 2) n1 = 0, n2 = 7;
                if (pre == 3) n1 = 6, n2 = 1;
                if (pre == 4) n1 = 6, n2 = 1;
                if (pre == 5) n1 = 7, n2 = 0;
                if (pre == 6) n1 = 3, n2 = 4;
                if (pre == 7) n1 = 2, n2 = 5;
                int sum1 = 0, sum2 = 0;
                for (int i = 0; i < 3; i++) {
                    if (now[i] != num[n1][i]) sum1++;
                }
                for (int i = 0; i < 3; i++) {
                    if (now[i] != num[n2][i]) sum2++;
                }
                if (sum1 > sum2) {
                    ans += sum2;
                    pre = n2;
                }
                else {
                    ans += sum1;
                    pre = n1;
                }
            }
        }
        else {
            char tmp[4], now[4];
            tmp[0] = g[0][0], tmp[1] = g[0][1], tmp[2] = g[0][2];
            int pre = lower_bound(num, num + 8, tmp) - num, n1, n2;
            for (int i = 1; i < n; i++) {
                now[0] = g[i][0], now[1] = g[i][1], now[2] = g[i][2];
                if (pre == 0) n1 = 2, n2 = 5;
                if (pre == 1) n1 = 4, n2 = 3;
                if (pre == 2) n1 = 0, n2 = 7;
                if (pre == 3) n1 = 6, n2 = 1;
                if (pre == 4) n1 = 6, n2 = 1;
                if (pre == 5) n1 = 7, n2 = 0;
                if (pre == 6) n1 = 3, n2 = 4;
                if (pre == 7) n1 = 2, n2 = 5;
                int sum1 = 0, sum2 = 0;
                for (int i = 0; i < 3; i++) {
                    if (now[i] != num[n1][i]) sum1++;
                }
                for (int i = 0; i < 3; i++) {
                    if (now[i] != num[n2][i]) sum2++;
                }
                if (sum1 > sum2) {
                    ans += sum2;
                    pre = n2;
                }
                else {
                    ans += sum1;
                    pre = n1;
                }
            }
        }
        cout << ans << '\n';
        return 0;
    }
    else if (n == 2 || m == 2) {
        int ans = 0;
        g.resize(n);
        for (int i = 0; i < n; i++) {
            g[i].resize(m);
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }
        if (n == 2) {
            char tmp[3], now[3];
            tmp[0] = g[0][0], tmp[1] = g[1][0];
            int pre = lower_bound(num1, num1 + 4, tmp) - num1, n1, n2;
            for (int i = 1; i < m; i++) {
                now[0] = g[0][i], now[1] = g[1][i];
                if (pre == 0) n1 = 2, n2 = 1;
                if (pre == 1) n1 = 3, n2 = 0;
                if (pre == 2) n1 = 3, n2 = 0;
                if (pre == 3) n1 = 2, n2 = 1;
                int sum1 = 0, sum2 = 0;
                for (int i = 0; i < 2; i++) {
                    if (now[i] != num1[n1][i]) sum1++;
                }
                for (int i = 0; i < 3; i++) {
                    if (now[i] != num1[n2][i]) sum2++;
                }
                if (sum1 > sum2) {
                    ans += sum2;
                    pre = n2;
                }
                else {
                    ans += sum1;
                    pre = n1;
                }
            }
        }
        else {
            char tmp[3], now[3];
            tmp[0] = g[0][0], tmp[1] = g[0][1];
            int pre = lower_bound(num1, num1 + 4, tmp) - num1, n1, n2;
            for (int i = 1; i < m; i++) {
                now[0] = g[i][0], now[1] = g[i][1];
                if (pre == 0) n1 = 2, n2 = 1;
                if (pre == 1) n1 = 3, n2 = 0;
                if (pre == 2) n1 = 3, n2 = 0;
                if (pre == 3) n1 = 2, n2 = 1;
                int sum1 = 0, sum2 = 0;
                for (int i = 0; i < 2; i++) {
                    if (now[i] != num1[n1][i]) sum1++;
                }
                for (int i = 0; i < 3; i++) {
                    if (now[i] != num1[n2][i]) sum2++;
                }
                if (sum1 > sum2) {
                    ans += sum2;
                    pre = n2;
                }
                else {
                    ans += sum1;
                    pre = n1;
                }
            }
        }
        cout << ans << '\n';
        return 0;
    }
}