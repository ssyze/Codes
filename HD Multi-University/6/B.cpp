/*
 * @Date         : 2020-08-06 13:31:49
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
const int inf = 0x3f3f3f3f;

string str;

int w(char c)
{
    if (isdigit(c))
        return c - '0';
    else
        return c - 'A' + 10;
}

string itos(int x)
{
    string res = "";
    while (x) {
        res += x % 10 + '0';
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string stoi(int base, string s, int l, int r)
{
    int b = 1, res = 0;
    for (int i = r; i >= l; --i, b *= base) {
        res += w(s[i]) * b;
    }
    return itos(res);
}

bool solve(int base, string s)
{
    string res = "";
    int ll = 0, rr = 0;
    for (int i = 0; i < s.length(); ++i) {
        if ((isdigit(s[i]) || isalpha(s[i])) && w(s[i]) >= base) return false;
        if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '=') {
            res += stoi(base, s, ll, rr);
            res += s[i];
            ll = i + 1;
        }
        rr = i;
        if (i == s.length() - 1) res += stoi(base, s, ll, rr);
    }
    stringstream ss;
    ss << res;
    int a, b, c;
    char ch = ' ';
    while (ss.peek() != EOF) {
        if (isdigit(ss.peek())) {
            if (ch == ' ')
                ss >> a;
            else
                ss >> b;
        }
        else if (ss.peek() != '=')
            ch = ss.get();
        else
            ss.get(), ss >> c;
    }
    cout << base << ":" << a << " " << ch << " " << b << " = " << c << endl;
    if (ch == '+') return a + b == c;
    if (ch == '-') return a - b == c;
    if (ch == '*') return a * b == c;
    if (ch == '/') return c * b == a;
}

signed main()
{
    while (cin >> str) {
        for (int i = 2; i <= 16; ++i) {
            if (solve(i, str)) {
                cout << i << endl;
                goto nxt;
            }
        }
        cout << -1 << endl;
    nxt:;
    }
}
