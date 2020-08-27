/*
 * @Date         : 2020-08-11 15:30:24
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;

void solve(int x, int y)
{
    vector<pair<int, int>> v;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            if (__gcd(x + i, y + j) != 1) v.push_back({x + i, y + j});
        }
    }
    cout << "z: " << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << endl;
        ;
    }
    cout << endl;
}

int main()
{
    int x, y;
    while (cin >> x >> y) {
        solve(x, y);
    }
}
