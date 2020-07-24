/*
 * @Date         : 2020-02-08 13:37:38
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int prime[maxn] = { 0 }, phi[maxn] = { 0 }, tot;
void euler()
{
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!phi[i]) {
            prime[tot++] = i;

            phi[i] = i - 1;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}
int n, m;
int ans[maxn];
int main()
{
    euler();
    cin >> n >> m;
    for (int i = 4; i <= n; i++) {
        int sum = 0;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                int t1 = j;
                int t2 = i / j;
                int pos1 = lower_bound(prime, prime + tot, t1) - prime;
                if (prime[pos1] != t1)
                    sum++;
                pos1 = lower_bound(prime, prime + tot, t2) - prime;
                if (prime[pos1] != t2 && j * j != i)
                    sum++;
            }
        }
        int pos1 = lower_bound(prime, prime + tot, i) - prime;
        if (prime[pos1] != i)
            sum++;
        ans[sum]++;
    }
    while (m--) {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
}