/*
 * @Date         : 2019-12-28 14:05:32
 * @Author       : ssyze
 * @Description  : 
 */
/*
 * @Date         : 2019-12-28 14:05:32
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
struct node {
    double a, b;
} a[1020];
bool cmp(node x, node y)
{
    if (x.a == y.a)
        return x.b < y.b;
    return x.a < y.a;
}
int n, g = 1, sum;
double m;
int main()
{
    while (cin >> n >> m && n && m) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].a >> a[i].b;
            if (abs(a[i].b) > m)
                k = 1;
            else {
                a[i].a = a[i].a - (double)sqrt(m * m - a[i].b * a[i].b);
                a[i].b = a[i].a + 2.0 * (double)sqrt(m * m - a[i].b * a[i].b);
            }
        }
        if (k == 0) {
            sort(a, a + n, cmp);
            int p = 0;
            sum = 1;
            for (int i = 1; i < n; i++) {
                if (a[i].a > a[p].b) {
                    sum++;
                    p = i;
                }
                else if (a[i].b < a[p].b) {
                    p = i;
                }
            }
        }
        printf("Case %d: ", g++);
        if (k == 1)
            printf("-1\n");
        else
            printf("%d\n", sum);
    }
}