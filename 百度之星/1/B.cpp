/*
 * @Date         : 2020-07-19 14:16:23
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t, a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int, double> p[11];
    p[0].first = 95, p[0].second = 4.3;
    p[1].first = 90, p[1].second = 4.0;
    p[2].first = 85, p[2].second = 3.7;
    p[3].first = 80, p[3].second = 3.3;
    p[4].first = 75, p[4].second = 3.0;
    p[5].first = 70, p[5].second = 2.7;
    p[6].first = 67, p[6].second = 2.3;
    p[7].first = 65, p[7].second = 2.0;
    p[8].first = 62, p[8].second = 1.7;
    p[9].first = 60, p[9].second = 1.0;
    p[10].first = 0, p[10].second = 0.0;
    cin >> t;
    while (t--) {
        cin >> a;
        double ans = -1.0;
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                for (int k = 0; k < 11; k++) {
                    for (int o = 0; o < 11; o++) {
                        int sum =
                            p[i].first + p[j].first + p[k].first + p[o].first;
                        double score = p[i].second + p[j].second + p[k].second +
                                       p[o].second;
                        if (sum <= a) ans = max(ans, score);
                    }
                }
            }
        }
        printf("%.1f\n", ans);
    }
}