/*
 * @Date         : 2020-03-28 18:54:16
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int father[maxn], n, cnt[maxn];

void init()
{
    for (int i = 1; i < maxn; i++) {
        father[i] = i;
        cnt[i] = 1;
    }
}

int Find(int x) { return father[x] == x ? x : father[x] = Find(father[x]); }

int Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if (fx != fy) {
        cnt[fx] += cnt[fy];
        father[fy] = fx;
    }
}

int main()
{
    while (cin >> n) {
        init();
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= 100000; i++) {
            ans = max(ans, cnt[i]);
        }
        cout << ans << endl;
    }
}