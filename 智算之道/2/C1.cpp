/*
 * @Date         : 2020-08-09 16:01:11
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll k, n;
ll fac[70];
vector<pair<int, int> > edge;
int main()
{
    fac[1] = 1, fac[2] = 1;
    for (int i = 3; i < 70; i++) fac[i] = fac[i - 1] * 2;
    cin >> k >> n;
    ll N;
    if (k == 1)
        N = 2;
    else
        N = int(log2(k - 1)) + 3;
    if (N == 67) N = 66;
    // while (tmp < k) tmp *= 2, N++;
    ll ed = N;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            edge.push_back(make_pair(i, j));
        }
    }
    if (k == fac[N]) {
        for (int i = 1; i <= N - 1; i++) edge.push_back(make_pair(i, ed));
    }
    else {
        int ps = 2;
        ll tmp = k;
        while (tmp) {
            if (tmp & 1) edge.push_back(make_pair(ps, N));
            tmp >>= 1;
            ps++;
        }
    }
    int sz = edge.size();
    cout << N << ' ' << sz << '\n';
    for (int i = 0; i < edge.size(); i++) printf("%d %d\n", edge[i].first, edge[i].second);
}