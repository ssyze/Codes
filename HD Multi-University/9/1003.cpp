/*
 * @Date         : 2020-08-18 14:29:20
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int j = 1; j <= 10; j++) {
        map<int, int> mp;
        int a = 0, b = 0;
        double l = 0, r = 1;
        mp[0] = 1;
        for (int i = j; i < 10000;) {
            a++;
            if (mp.find(a) == mp.end()) {
                b = a + i;
                mp[b] = 1;
                mp[a] = 1;
                double ll = (double)a / (double)i;
                double rr = (double)(a + 1) / (double)i;
                if (ll > l) l = ll;
                if (rr < r) r = rr;
                i += j;
            }
        }
        printf("%d %.10f %.10f\n", j, l, r);
    }
}