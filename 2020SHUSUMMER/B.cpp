#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
using namespace std;
typedef long long ll;
string s;
ll c, h, o;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int len = s.length();
    for (int i = 0; i < 10000; i++) s += 'x';
    for (int i = 0; i < len;) {
        if (s[i] == 'x') break;
        if (s[i] == 'C' || s[i] == 'O' || s[i] == 'H') {
            ll num = 1, type;
            if (s[i] == 'C') type = 1;
            if (s[i] == 'O') type = 2;
            if (s[i] == 'H') type = 3;
            if (s[i + 1] == 'x') {
                if (type == 1) c += num;
                if (type == 2) o += num;
                if (type == 3) h += num;
                break;
            }
            if (isdigit(s[i + 1])) {
                i++;
                int st = i;
                while (isdigit(s[i])) i++;
                int len = i - st;
                num = stoll(s.substr(st, len).c_str());
                i--;
            }
            if (type == 1) c += num;
            if (type == 2) o += num;
            if (type == 3) h += num;
        }
        else {
            i++;
            int _c = 0, _h = 0, _o = 0;
            while (s[i] != ')') {
                if (s[i] == 'C' || s[i] == 'O' || s[i] == 'H') {
                    ll num = 1, type;
                    if (s[i] == 'C') type = 1;
                    if (s[i] == 'O') type = 2;
                    if (s[i] == 'H') type = 3;
                    if (isdigit(s[i + 1])) {
                        i++;
                        int st = i;
                        while (isdigit(s[i])) i++;
                        int len = i - st;
                        num = stoll(s.substr(st, len).c_str());
                        i--;
                    }
                    if (type == 1) _c += num;
                    if (type == 2) _o += num;
                    if (type == 3) _h += num;
                }
                i++;
            }
            if (s[i + 1] == 'x') {
                c += _c;
                o += _o;
                h += _h;
                break;
            }
            ll num = 1;
            if (isdigit(s[i + 1])) {
                i++;
                int st = i;
                while (isdigit(s[i])) i++;
                int len = i - st;
                num = stoll(s.substr(st, len).c_str());
                i--;
            }
            c += _c * num;
            o += _o * num;
            h += _h * num;
        }
        i++;
        // cout << c << ' ' << o << ' ' << h << endl;
    }
    cout << h * 1LL + o * 17LL + c * 13LL << endl;
}