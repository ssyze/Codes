/*
 * @Date         : 2020-01-29 12:19:50
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
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

int main()
{
    euler();
    //cout << prime[0] << endl;
    int n;
    cin >> n;
    for (int i = 0; i < tot; i++) {
        int tmp1 = prime[i];
        int tmp2 = lower_bound(prime, prime + tot, n - tmp1) - prime;
        if (prime[tmp2] == n - tmp1) {
            cout << tmp1 << ' ' << prime[tmp2] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}