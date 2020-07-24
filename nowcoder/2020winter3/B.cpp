#include <bits/stdc++.h>
using namespace std;
char g[50][50];
int k;
int main()
{
    cin >> k;
    int n = 32, m = 30;
    for (int i = 1; i <= m; i++) {
        g[i][i] = 'B';
        g[i + 1][i] = 'R';
        g[i][i + 1] = 'D';
        for (int j = i + 2; j <= m; j++) {
            g[i][j] = 'R';
        }
        for (int j = i - 2; j >= 1; j--) {
            g[i][j] = 'D';
        }
    }
    for (int j = 1; j < m; j++) {
        g[31][j] = 'D';
        g[32][j] = 'R';
    }
    g[30][29] = 'R';
    g[32][30] = 'R';
    int cnt = 1;
    while (k) {
        if (k & 1)
            g[cnt + 1][cnt] = 'B';
        k >>= 1;
        cnt++;
    }
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << g[i][j];
        cout << endl;
    }
}