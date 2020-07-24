/*
 * @Date         : 2020-02-04 15:16:19
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, k, ans = -1;
string s;
int main()
{
    cin >> n >> k;
    cin >> s;
    int st = 0, ed = 0, num0 = 0, num1 = 0;
    if (s[0] == '0')
        num0++;
    else
        num1++;
    while (st < s.length() && ed < s.length()) {
        if (min(num0, num1) > k) {
            if (s[st++] == '0')
                num0--;
            else
                num1--;
        }
        else {
            ans = max(ans, ed - st + 1);
            ed++;
            if (s[ed] == '0')
                num0++;
            else
                num1++;
        }
    }
    cout << ans << endl;
}