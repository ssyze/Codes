/*
 * @Date         : 2020-02-11 13:29:19
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
char l[maxn];
string s;
bool solve()
{
    if (s[0] == ')' || s[0] == ']' || s[0] == '}')
        return 0;
    int idx = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            l[idx++] = s[i];
        }
        else {
            if (idx == 0) {
                return 0;
            }
            else if (s[i] == ')' && l[idx - 1] == '(') {
                idx--;
                continue;
            }
            else if (s[i] == ']' && l[idx - 1] == '[') {
                idx--;
                continue;
            }
            else if (s[i] == '}' && l[idx - 1] == '{') {
                idx--;
                continue;
            }
        }
    }
    if (idx == 0)
        return 1;
    else
        return 0;
}
int main()
{
    cin >> s;
    if (solve())
        puts("Yes");
    else
        puts("No");
}