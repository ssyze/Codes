#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define mp make_pair
#define ALL(x) x.begin(), x.end()

typedef long long ll;
// const double PI = 4*atan(1.);
// const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
const int mod = 998244353;

bool vis[maxn];
int prime[maxn];
int sz = 0;

void pre()
{
    for (int i = 2; i < maxn; ++i) {
        if (!vis[i]) prime[++sz] = i;
        for (int j = 1; j <= sz; ++j) {
            ll tmp = (ll)i * prime[j];
            if (tmp >= maxn) break;
            vis[tmp] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

map<int, int> mmp;
int X[maxn + 5], Y[maxn + 5];

void getFac(int* p, int x)
{
    for (int i = 1; prime[i] <= x / prime[i] && i <= sz; ++i) {
        int tmp = prime[i];
        if (x % tmp == 0) {
            int cnt = 0;
            while (x % tmp == 0) {
                x /= tmp;
                ++cnt;
            }
            p[tmp] = cnt;
            ++mmp[tmp];
        }
    }
    if (x > 1) {
        p[maxn] = x;
        ++mmp[x];
    }
}

ll qpow(ll a, ll b)
{
    a %= mod;
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int a, b, c, d, x, y;
    cin >> a >> b >> c >> d >> x >> y;
    pre();
    getFac(X, x);
    getFac(Y, y);
    ll ans = 1;
    for (auto& cur : mmp) {
        if (cur.second == 2) {
            int pr = cur.first;
            int ex = pr == X[maxn] ? 1 : X[pr], lwx = ex * a;
            int ey = pr == Y[maxn] ? 1 : Y[pr], lwy = ey * c;
            int mx = b * ex, my = d * ey;
            cout << pr << ' ' << ex << ' ' << ey << '\n';
            cout << lwx << ' ' << mx << ' ' << lwy << ' ' << my << endl;
            ll sum = 0;
            for (int i = a * ex; i <= mx && i <= my; i += ex) {  // x low
                ll tmp = (my - max(i, lwy)) / ey + 1;
                (sum += i * tmp) %= mod - 1;
            }
            (ans *= qpow(pr, sum)) %= mod;
            cout << ans << endl;
            // cout << "x low sum ans: " << sum << ' ' << ans << '\n';
            sum = 0;
            for (int i = c * ey; i < mx && i <= my; i += ey) {  // y low
                ll tmp = (mx - max(i + 1, lwx)) / ex + 1;
                (sum += i * tmp) %= mod - 1;
            }
            (ans *= qpow(pr, sum)) %= mod;
            // cout << "y low sum ans: " << sum << ' ' << ans << '\n';
        }
    }
    cout << ans << '\n';
    return 0;
}