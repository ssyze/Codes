#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e5 + 100;
const int inf = 0x3f3f3f3f;

int mm[30][30];

int main()
{
    int n;
    cin >> n;
    while (n--) {
        memset(mm, 0, sizeof(mm));
        int t;
        cin >> t;
        if (t == 1) {
            cout << 1 << ' ' << 2 << '\n';
            cout << "X." << '\n';
            continue;
        }
        else if (t == 0) {
            cout << "1 1\n";
            cout << ".\n";
            continue;
        }
        else if (t == 2) {
            cout << 1 << ' ' << 3 << '\n';
            cout << ".X." << '\n';
            continue;
        }
        else if (t == 3) {
            cout << 2 << ' ' << 2 << '\n';
            cout << ".X" << '\n';
            cout << ".." << '\n';
            continue;
        }
        else if (t == 4) {
            cout << 2 << ' ' << 2 << '\n';
            cout << ".X" << '\n';
            cout << ".X" << '\n';
            continue;
        }
        else if (t == 5) {
            cout << 2 << ' ' << 3 << '\n';
            cout << ".X." << '\n';
            cout << "..." << '\n';
            continue;
        }
        else if (t == 6) {
            cout << 2 << ' ' << 3 << '\n';
            cout << "X.X" << '\n';
            cout << "..." << '\n';
            continue;
        }
        else if (t == 6) {
            cout << 2 << ' ' << 3 << '\n';
            cout << "X.X" << '\n';
            cout << "..." << '\n';
            continue;
        }
        else if (t == 7) {
            cout << 2 << ' ' << 3 << '\n';
            cout << "XXX" << '\n';
            cout << "..." << '\n';
            continue;
        }

        int cnt = t / 8;
        // cout<<cnt<<endl;
        int x = 0;
        int flag = 0;
        for (int i = 3; i <= 23; i += 2) {
            for (int j = 3; j <= 23; j += 2) {
                mm[i][j] = 1, x++;
                if (x == cnt || x == 121) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        x = t % 8;
        if (cnt - 121 > 0) {
            x = t - 121 * 8;
            for (int i = 4; i < 22; i += 2) {
                mm[25][i] = 1;
                x -= 5;
                if (x < 5) break;
            }
        }
        // if (cnt - 121 > 0) x = ((cnt - 121) * 8) % 5;
        // cout << x << endl;
        if (x == 1) // 9
        {
            mm[1][1] = 1;
            mm[25][1] = 1;
            mm[1][25] = 1;
            mm[3][3] = 0;
        }
        else if (x == 2) {
            mm[1][2] = 1;
            mm[1][4] = 1;
            mm[3][3] = 0;
        }
        else if (x == 3) {
            mm[1][1] = 1;
        }
        else if (x == 4) {
            mm[1][1] = 1;
            mm[25][1] = 1;
            mm[1][25] = 1;
            mm[25][25] = 1;
            mm[3][3] = 0;
        }
        else if (x == 5) {
            mm[1][2] = 1;
        }
        else if (x == 6) {
            mm[1][1] = 1;
            mm[25][1] = 1;
        }
        else if (x == 7) {
            mm[1][2] = 1;
            mm[1][4] = 1;
            mm[1][6] = 1;
            mm[3][3] = 0;
        }
        cout << 25 << ' ' << 25 << '\n';
        for (int i = 1; i <= 25; i++) {
            for (int j = 1; j <= 25; j++) {
                if (mm[i][j] == 0)
                    cout << '.';
                else
                    cout << 'X';
            }
            cout << '\n';
        }
    }

    return 0;
}
