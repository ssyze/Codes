/*
 * @Date         : 2020-08-05 13:58:59
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
long long n, m, p, q;
string s;
map<string, string> mp;
map<char, string> mp1;
map<long long, long long> a;
string to2(long long x)
{
    string ans = "";
    while (x) {
        if (x & 1)
            ans += "1";
        else
            ans += "0";
        x >>= 1;
    }
    while (ans.length() < 32 - p) ans += "0";
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mp1['0'] = "0000", mp1['1'] = "0001", mp1['2'] = "0010", mp1['3'] = "0011";
    mp1['4'] = "0100", mp1['5'] = "0101", mp1['6'] = "0110", mp1['7'] = "0111";
    mp1['8'] = "1000", mp1['9'] = "1001", mp1['A'] = "1010", mp1['B'] = "1011";
    mp1['C'] = "1100", mp1['D'] = "1101", mp1['E'] = "1110", mp1['F'] = "1111";
    mp["0000"] = "0", mp["0001"] = "1", mp["0010"] = "2", mp["0011"] = "3";
    mp["0100"] = "4", mp["0101"] = "5", mp["0110"] = "6", mp["0111"] = "7";
    mp["1000"] = "8", mp["1001"] = "9", mp["1010"] = "A", mp["1011"] = "B";
    mp["1100"] = "C", mp["1101"] = "D", mp["1110"] = "E", mp["1111"] = "F";
    cin >> n >> m >> p;
    for (int i = 0; i < 1 << (m - p); i++) {
        int tmp;
        cin >> tmp;
        a[tmp] = i + 1;
    }
    cin >> q;
    while (q--) {
        cin >> s;
        string tmp = "";
        for (int i = 0; i < s.length(); i++) tmp += mp1[s[i]];
        long long num = stoll(tmp.substr(0, 32 - p).c_str(), nullptr, 2);
        if (a[num]) {
            string ans;
            ans = to2(a[num] - 1);
            ans += tmp.substr(32 - p);
            for (int i = 0; i < ans.length(); i += 4) {
                cout << mp[ans.substr(i, 4)];
            }
            cout << '\n';
        }
        else
            cout << "interrupt!\n";
    }
}