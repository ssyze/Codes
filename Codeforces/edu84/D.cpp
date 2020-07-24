/*
 * @Date         : 2020-03-26 09:21:33
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n;
bool vis[maxn];
int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> p(n), c(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            --p[i];
            vis[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> cur;
                int tmp = i;
                while (!vis[tmp]) {
                    vis[tmp] = 1;
                    cur.push_back(tmp);
                    tmp = p[tmp];
                }
                int len = cur.size();
                vector<int> fac;
                for (int j = 1; j * j <= len; j++) {
                    if (len % j == 0) {
                        fac.push_back(j);
                        if (j * j != len)
                            fac.push_back(len / j);
                    }
                }
                for (auto& x : fac) {
                    bool ok = 0;
                    for (int j = 0; j < x; j++) {
                        bool o = 1;
                        for (int k = j + x; k < cur.size(); k += x) {
                            if (c[cur[k]] != c[cur[k - x]]) {
                                o = 0;
                                break;
                            }
                        }
                        if (o) {
                            ok = 1;
                            break;
                        }
                    }
                    if (ok) {
                        ans = min(ans, x);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}