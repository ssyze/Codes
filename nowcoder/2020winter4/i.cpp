#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 100;
const int mod = 998244353;

int cnt = 1, idx;
string str;
vector<int> ans;

int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); ++i)
        if (str[i] == '+')
            cnt++;
    sort(str.begin(), str.end(), greater<char>());
    //cout << str << endl;
    int cur = 0;
    while (cur < str.length()) {
        if (str[cur] == '+')
            cur++;
        else {
            int sum = 0;
            for (int i = 0; i < cnt && cur + i < str.length() && str[cur + i] != '+'; ++i)
                sum += str[cur + i] - '0';
            //cout << sum << endl;
            ans.emplace_back(sum);
            cur = cur + cnt;
        }
    }
    for (int i = 0; i < ans.size() - 1; ++i) {
        if (ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    while (ans[ans.size() - 1] >= 10) {
        ans.emplace_back(ans[ans.size() - 1] / 10);
        ans[ans.size() - 2] %= 10;
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i];
}