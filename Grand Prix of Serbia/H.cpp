/*
 * @Date         : 2020-05-17 16:09:54
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
typedef long long ll;
int n;
pair<int, int> p[maxn];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
bool cmp1(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p + 1, p + 1 + n, cmp);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += abs(p[i].second - i);
    sort(p + 1, p + 1 + n, cmp1);
    for (int i = 1; i <= n; i++)
        sum += abs(p[i].first - i);
    cout << sum << endl;
}