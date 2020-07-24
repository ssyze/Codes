#include <bits/stdc++.h>
using namespace std;
string s;
bool cmp(char a, char b)
{
    return a > b;
}
int main()
{
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '+')
            cnt++;
    sort(s.begin(), s.end(), cmp);
    int pos = 0;
    vector<int> ans;
    while (pos < s.length()) {
        if (s[pos] == '+')
            break;
        int sum = 0;
        for (int i = 0; i <= cnt && pos + i < s.length() && s[pos + i] != '+'; i++) {
            sum += s[pos + i] - '0';
        }
        ans.push_back(sum);
        pos = pos + cnt + 1;
    }
    //cout << ans.size() << endl;
    for (int i = 0; i < ans.size() - 1; i++) {
        if (ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
    }
    while (ans[ans.size() - 1] >= 10) {
        ans.push_back(ans[ans.size() - 1] / 10);
        ans[ans.size() - 2] = ans[ans.size() - 2] % 10;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
}