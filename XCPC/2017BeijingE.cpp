#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 105;
int m, n, x;
int a[maxn];
pair<int, int> vis[maxn];
int main()
{
    while (scanf("%d%d%d", &m, &n, &x) != EOF) {
        for (int i = 0; i <= n; i++) vis[i].first = vis[i].second = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        for (int i = 0; i < x; i++) {
            for (int j = 1; j <= n; j++) {
                if (vis[j].first && ((i - vis[j].second) % a[j]) == 0) vis[j].first = 0;
            }
            for (int j = 1; j <= n && m; j++) {
                if (!vis[j].first) {
                    vis[j].first = 1, vis[j].second = i;
                    m--;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i].first && (x - vis[i].second) % a[i] == 0) vis[i].first = 0;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (vis[i].first) ans++;
        printf("%d %d\n", m, ans);
    }
}