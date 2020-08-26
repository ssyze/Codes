/*
 * @Date         : 2020-08-19 21:11:29
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        int len = 0;
        vector<int> ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                ans.push_back(len), len = 0;
            else
                len++;
        }
        ans.push_back(len);
        sort(ans.begin(), ans.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < ans.size(); i += 2) sum += ans[i];
        cout << sum << endl;
    }
}