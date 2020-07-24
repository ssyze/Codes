/*
 * @Date         : 2020-02-13 13:05:57
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 20;
int a[maxn];
vector<int> c[1005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[9] * 100 >= m * 80) {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        c[a[i]].push_back(i);
    }
    int sum = 0;
    for (int i = 1005; i >= 1; i--) {
        if (c[i].size()) {
            int tmp = 0;
            for (auto& x : c[i]) {
                if (x != 9)
                    tmp++;
                if (x == 9 && sum < 3) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            sum += tmp;
            if (sum >= 3) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
}