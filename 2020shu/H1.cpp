/*
 * @Date         : 2020-04-18 14:07:35
 * @Author       : ssyze
 * @Description  : 
 */
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
const int N = 1e5 + 1;
int t, k, c[10], p[3], x, A[N], v;
string s;
int C(int x, int y, int z, int k, int w)
{
    for (int i = 0; i <= min(2, y); i++)
        for (int j = 0; j <= min(2, z); j++)
            if (k >= i + j && (i + 2 * j) % 3 == w && min((k - i - j) / 3 * 3, (y - i) / 3 * 3 + (z - j) / 3 * 3) + x >= k - i - j)
                return 1;
    return 0;
}
int main()
{
    cin >> t;
    while (t-- && cin >> s >> k) {
        memset(c, 0, sizeof(c)), v = 1, x = p[0] = p[1] = p[2] = 0;
        for (int i = 0; i < s.size(); i++)
            c[s[i] - '0']++, p[(s[i] - '0') % 3]++;
        for (int i = 1; i <= k; i++)
            A[i] = -1;
        for (int i = 1; i <= k; i++) {
            for (int j = 9; j >= 0; j--)
                if (c[j]) {
                    p[j % 3]--, c[j]--, x += j;
                    if (C(p[0], p[1], p[2], k - i, (3 - x % 3) % 3)) {
                        A[i] = j;
                        break;
                    }
                    p[j % 3]++, c[j]++, x -= j;
                }
            if (A[i] == -1)
                v = 0;
        }
        if (!v || (A[1] == 0 && k != 1)) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 1; i <= k; i++)
            cout << A[i];
        cout << '\n';
    }
    return 0;
}
