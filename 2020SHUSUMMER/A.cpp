/*
 * @Date         : 2020-08-05 12:57:48
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
using namespace std;
typedef long long ll;

const int maxn = 5e3 + 10;
int prime[maxn] = {0}, phi[maxn] = {0}, tot;

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

ll power(ll v, ll p, ll m)
{
    ll r = 1;
    while (p) {
        if (p & 1) r = r * v % m;
        v = v * v % m;
        p >>= 1;
    }

    return r;
}

bool witness(ll a, ll p)
{
    int k = 0;
    ll q = p - 1;
    while ((q & 1) == 0) ++k, q >>= 1;
    ll v = power(a, q, p);
    if (v == 1 || v == p - 1) return false;  // probably prime number
    while (k-- != 0) {
        v = v * v % p;
        if (v == p - 1) return false;
    }

    return true;  // composite number
}

bool miller_rabin(ll p)
{
    if (p == 1) return false;
    if (p == 2) return true;
    if (p % 2 == 0) return false;

    for (int i = 0; i != 50; ++i) {
        ll a = std::rand() % (p - 1) + 1;
        if (witness(a, p)) return false;
    }

    return true;
}
ll t, n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    euler();
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ll a[3], num = 0;
        if (n % k != 0 || n == 1) {
            cout << "-1 -1 -1\n";
            continue;
        }
        ll nn = n / k;
        ll tmp = nn / 3;
        /* if (tmp <= 1000) {
            int flag = 0, bk = 1;
            for (int i = 1; i <= tmp + 5; i++) {
                for (int j = 1; j <= tmp + 5; j++) {
                    int num = nn - i - j;
                    if (num <= 0) break;
                    a[0] = i * k, a[1] = j * k, a[2] = num * k;
                    if (__gcd(a[0], a[1]) == k && __gcd(a[1], a[2]) == k &&
                        __gcd(a[0], a[2]) == k && a[0] != k && a[1] != k && a[2] != k &&
                        a[0] + a[1] + a[2] == n) {
                        cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
            }
            if (!flag) cout << "-1 -1 -1\n";
            continue;
        } */
        int flag = 0;
        for (ll i = max(2LL, tmp - 1000); i <= tmp + 1000; i++) {
            a[0] = i * k, a[1] = (i + 2) * k, a[2] = (nn - i - i - 2) * k;
            if (a[2] <= 1) break;
            if (__gcd(a[0], a[1]) == k && __gcd(a[1], a[2]) == k && __gcd(a[0], a[2]) == k &&
                a[0] != k && a[1] != k && a[2] != k && a[0] + a[1] + a[2] == n) {
                cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
                flag = 1;
            }
            if (flag) break;
        }
        if (!flag) {
            for (ll i = max(2LL, tmp - 1000); i <= tmp + 1000; i++) {
                a[0] = i * k, a[1] = (i + 1) * k, a[2] = (nn - i - i - 1) * k;
                if (a[2] <= 1) break;
                if (__gcd(a[0], a[1]) == k && __gcd(a[1], a[2]) == k && __gcd(a[0], a[2]) == k &&
                    a[0] != k && a[1] != k && a[2] != k && a[0] + a[1] + a[2] == n) {
                    cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
                    flag = 1;
                }
                if (flag) break;
            }
        }
        if (!flag) cout << "-1 -1 -1\n";
    }
}