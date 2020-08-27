/*
 * @Date         : 2020-08-10 15:01:59
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
char g[10][10];
int h, w, k;
int r[10], c[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w >> k;
    int tot = 0, ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
            if (g[i][j] == '#') tot++;
        }
    }
    for (int i = 0; i < h; i++) {
        int sum = 0;
        for (int j = 0; j < w; j++) {
            if (g[i][j] == '#') sum++;
        }
        r[i] = sum;
    }
    for (int i = 0; i < w; i++) {
        int sum = 0;
        for (int j = 0; j < h; j++) {
            if (g[j][i] == '#') sum++;
        }
        c[i] = sum;
    }
    for (int i = 0; i < 1 << h; i++) {
        for (int j = 0; j < 1 << w; j++) {
            vector<int> row, col;
            int tmp1 = j, tmp2 = i, tt1 = 0, tt2 = 0;
            while (tmp1) {
                if (tmp1 & 1) col.push_back(tt1);
                tt1++;
                tmp1 >>= 1;
            }
            while (tmp2) {
                if (tmp2 & 1) row.push_back(tt2);
                tt2++;
                tmp2 >>= 1;
            }
            int res = tot;
            for (auto& x : col) res -= c[x];
            for (auto& x : row) res -= r[x];
            for (auto& x : row) {
                for (auto& y : col) {
                    if (g[x][y] == '#') res++;
                }
            }
            if (res == k) ans++;
        }
    }
    cout << ans << endl;
}