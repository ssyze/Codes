/*
 * @Date         : 2019-12-19 22:55:49
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin >> s;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            s[i] += 1;
            if (s[i] > 'z')
                s[i] = 'a';
            if (s[i] == s[i + 1])
                s[i] += 1;
            if (s[i] > 'z')
                s[i] = 'a';
        }
    }
    cout << s << endl;
}