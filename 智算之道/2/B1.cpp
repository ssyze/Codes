/*
 * @Date         : 2020-08-09 14:19:07
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2005;
ll n, w1, w2, k, x[maxn], y[maxn];
struct point {
    ll x, y, num = 0;
} p[maxn];
bool cmp(point a, point b) { return a.num > b.num; }
int main()
{
    scanf("%d%d%d%d", &n, &k, &w1, &w2);
    for (int i = 0; i < k; i++) scanf("%d%d", &p[i].x, &p[i].y);
    if (w2 > 2 * w1) {
        printf("%lld\n", 1LL * n * 2 * w1);
        return 0;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (p[j].x > p[i].x && p[j].y > p[i].y) p[i].num++;
        }
    }
    sort(p, p + k, cmp);
    ll nx = 0, ny = 0, sum = 0, sum1 = 0;
    for (int i = 0; i < k; i++) {
        if (p[i].x >= nx && p[i].y >= ny && p[i].x != n && p[i].y != n) {
            sum += (p[i].x - nx + p[i].y - ny);
            nx = p[i].x + 1, ny = p[i].y + 1;
            sum1++;
        }
        if (p[i].num == 0) break;
    }
    sum += (n - nx + n - ny);
    ll ans = 1LL * sum * w1 + 1LL * sum1 * w2;
    printf("%lld\n", ans);
}