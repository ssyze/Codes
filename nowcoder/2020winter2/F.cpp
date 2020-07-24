/*
 * @Date         : 2020-02-06 16:46:46
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
struct object {
    int a, b, sum, id;
} a[maxn];
int vis[maxn];
int n;
bool cmp(object a, object b)
{
    return a.sum > b.sum;
}

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].a;
    for (int i = 0; i < n; i++)
        cin >> a[i].b;
    for (int i = 0; i < n; i++) {
        a[i].sum = a[i].a + a[i].b;
        a[i].id = i + 1;
    }
    sort(a, a + n, cmp);
    vector<int> ans1, ans2;
    for (int i = 0; i < n; i += 2)
        ans1.push_back(a[i].id);
    for (int i = 1; i < n; i += 2)
        ans2.push_back(a[i].id);
    for (auto& x : ans1)
        cout << x << ' ';
    cout << endl;
    for (auto& x : ans2)
        cout << x << ' ';
    cout << endl;
}