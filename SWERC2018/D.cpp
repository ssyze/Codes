/*
 * @Date         : 2020-06-16 21:13:08
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, x, y;
pair<int, int> p[maxn];
int ef1(int i)
{
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) >> 1;
        if (p[m].first > p[i].first)
            r = m;
        else
            l = m + 1;
    }
    return r;
}
int ef2(int i, int now, int nxt)
{
    int l = i, r = nxt - 1;
    while (l < r) {
        int m = (l + r) >> 1;
        if (p[m].second > now)
            r = m;
        else
            l = m + 1;
    }
    return r;
}
int s(int pos)
{
    int sum = 0, i = 0;
    while (1) {
        int pos1 = ef1(i); //x坐标大于当前的第一个点
        pos1 -= 1;
        if (pos1 == i)
            sum += 2 * abs(p[i].second - pos);
        else {
            if (p[i].second <= pos && p[pos1].second >= pos) {
                sum += 2 * (pos - p[i].second);
                sum += 2 * (p[pos1].second - pos);
            } else {
                if (p[i].second >= pos)
                    sum += 2 * (p[pos1].second - pos);
                else
                    sum += 2 * (pos - p[i].second);
            }
        }
        //cout << sum << endl;
        i = pos1 + 1;
        if (i == n)
            break;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    int num = 0, sum1 = 0, i = 0;
    while (1) {
        int pos1 = ef1(i);
        pos1 -= 1;
        if (i == pos1) {
            num++;
            sum1 += p[i].first;
        } else {
            num += 2;
            sum1 += p[i].first;
            sum1 += p[pos1].first;
        }
        i = pos1 + 1;
        if (i == n)
            break;
    }
    int pos = sum1 / num;
    int ans = 0x3f3f3f3f;
    for (int i = pos - 100; i <= pos + 100; i++)
        ans = min(ans, s(i));
    cout << ans + x - 1 << endl;
}