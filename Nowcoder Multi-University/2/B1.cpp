/*
 * @Date         : 2020-07-13 15:45:27
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const double eps = 1e-6;
int n;
pair<int, int> p[maxn];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        double a = double(p[i].first) / 2.0;
        double b = double(p[i].second) / 2.0;
        double r = a * a + b * b;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            double tmp = double(p[j].first) - a;
            tmp = tmp * tmp;
            double tmp2 = double(p[j].second) - b;
            tmp2 = tmp2 * tmp2;
            if (fabs(tmp + tmp2 - r) <= eps) sum++;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}