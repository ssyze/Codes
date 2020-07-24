/*
 * @Date         : 2020-07-12 19:33:44
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
string s, t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    vector<int> s1(27), t1(27);
    int len = s.length();
    set<string> st;
    for (int i = 0; i < s.length(); i++) s1[s[i] - 'a']++;
    for (int i = 0; i < s.length(); i++) t1[t[i] - 'a']++;
    for (int i = s.length(); i < t.length(); i++) {
        // cout << i << ' ';
        int flag = 1;
        for (int j = 0; j < 26; j++)
            if (s1[j] != t1[j]) {
                flag = 0;
                break;
            }
        if (flag) st.insert(t.substr(i - len, len));
        // cout << t.substr(i - len, len) << endl;
        t1[t[i] - 'a']++;
        t1[t[i - len] - 'a']--;
    }
    int flag = 1;
    for (int j = 0; j < 26; j++)
        if (s1[j] != t1[j]) {
            flag = 0;
            break;
        }
    if (flag) st.insert(t.substr(t.length() - len, len));
    cout << st.size() << endl;
}