/*
 * @Date         : 2020-04-18 20:32:02
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, k, ans[maxn];
string s;
bool check(int s0, int s1, int s2, int k, int m)
// 余数为0,1,2的个数，还需要多少位k，需要凑成的余数为m
{
    if (k == 0) {
        if (m == 0)
            return 1;
        return 0;
    }
    if (k == 1) {
        if (m == 1 && s1 >= 1)
            return 1;
        if (m == 2 && s2 >= 1)
            return 1;
        if (m == 0 && s0 >= 1)
            return 1;
        return 0;
    }
    s0 = min(s0, k), s1 = min(s1, k), s2 = min(s2, k);
    //cout << s1 << ' ' << s2 << ' ' << m << endl;
    if (s0 + s1 + s2 < k)
        return 0;
    if (s0 + s1 + s2 == k)
        return ((s1 + 2 * s2) % 3) == m;
    if (s0 * s1 * s2 == 0) {
        if (s1 && s2) {
            if (s1 + s2 > k + 1)
                return 1;
            else
                return ((s1 + 2 * s2 + 1) % 3 == m) || ((s1 + 2 * s2 + 2) % 3 == m);
        }
        if (s0 && s1) {
            if (m == 0) {
                int x = k - (s1 / 3) * 3;
                if (x <= 0 || s0 >= x)
                    return 1;
                else
                    return 0;
            }
            if (m == 1) {
                k--;
                s1--;
                int x = k - (s1 / 3) * 3;
                if (x <= 0 || s0 >= x)
                    return 1;
                return 0;
            }
            if (m == 2) {
                if (s1 < 2)
                    return 0;
                k -= 2, s1 -= 2;
                int x = k - (s1 / 3) * 3;
                if (x <= 0 || s0 >= x)
                    return 1;
                return 0;
            }
        }
        if (s0 && s2) {
            if (m == 0) {
                int x = k - (s2 / 3) * 3;
                if (x <= 0 || s0 >= x)
                    return 1;
                else
                    return 0;
            }
            if (m == 2) {
                k--;
                s2--;
                int x = k - (s2 / 3) * 3;
                if (x <= 0 || s0 >= x)
                    return 1;
                return 0;
            }
            if (m == 1) {
                if (s2 < 2)
                    return 0;
                k -= 2, s2 -= 2;
                int x = k - (s2 / 3) * 3;
                if (x <= 0 || s0 >= x)
                    return 1;
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s >> k;
        vector<int> v(10, 0), mod(3, 0);
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - '0']++;
            mod[(s[i] - '0') % 3]++;
        }
        for (int i = 1; i <= k; i++)
            ans[i] = -1;
        int flag = 1, m = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 9; j >= 0; j--) {
                if (v[j]) {
                    //cout << j << ' ' << v[j] << endl;
                    v[j]--;
                    mod[j % 3]--;
                    int t = 3 - m - j;
                    t = (t % 3 + 3) % 3;
                    int f = check(mod[0], mod[1], mod[2], k - i, t);
                    if (f) {
                        ans[i] = j;
                        m = (m + j) % 3;
                        break;
                    }
                    v[j]++;
                    mod[j % 3]++;
                }
            }
            if (ans[i] == -1 || (ans[1] == 0 && k != 1)) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int i = 1; i <= k; i++)
                cout << ans[i];
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}