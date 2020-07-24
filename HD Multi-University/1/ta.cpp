/*
 * @Date         : 2020-07-21 12:36:00
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    int t = 0;
    for (char i = 'a'; i <= 'b'; i++) {
        for (char j = 'a'; j <= 'b'; j++) {
            for (char k = 'a'; k <= 'b'; k++) {
                string s, a, b, c;
                a = i;
                b = j;
                c = k;
                s = a + b + c;
                t++;
                mp[s.substr(0)]++;
                mp[s.substr(0, 1)]++;
                mp[s.substr(0, 2)]++;
                mp[s.substr(1)]++;
                mp[s.substr(2)]++;
                mp[s.substr(1, 2)]++;
                cout << s.substr(0) << endl;
                cout << s.substr(1) << endl;
                cout << s.substr(2) << endl;
                cout << s.substr(0, 1) << endl;
                cout << s.substr(0, 2) << endl;
                cout << s.substr(1, 2) << endl;
            }
        }
    }
    cout << t << endl;
    cout << mp.size() << endl;
}