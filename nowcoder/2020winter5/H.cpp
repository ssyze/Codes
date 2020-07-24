/*
 * @Date         : 2020-02-13 15:52:25
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int LEN = 6;
int mod;
int Hash(string str)
{
    int res = 0;
    for (int i = 0; i < LEN; i++) {
        res = (res * 26 + str[i] - 'a');
    }
    return res;
}
string s;
int main()
{
    while (cin >> s >> mod) {
        int cur = Hash(s) + mod;
        string s1;
        while (cur) {
            int tmp = cur % 26;
            cur /= 26;
            //cout << tmp << endl;
            s1 += tmp + 'a';
        }
        while (s1.size() < 6)
            s1 += 'a';
        reverse(s1.begin(), s1.end());
        if (s1 <= s)
            cout << -1 << endl;
        else
            cout << s1 << endl;
    }
}