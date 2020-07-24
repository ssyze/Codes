/*
 * @Date         : 2020-07-16 23:34:10
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
    cin >> t;
    while (t--) {
        cin >> s;
        pair<int, char> cnt[3];
        cnt[0].second = 'P';
        cnt[1].second = 'S';
        cnt[2].second = 'R';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R')
                cnt[0].first++;
            else if (s[i] == 'P')
                cnt[1].first++;
            else
                cnt[2].first++;
        }
        sort(cnt, cnt + 3);
        for (int i = 0; i < s.length(); i++) cout << cnt[2].second;
        cout << endl;
    }
}