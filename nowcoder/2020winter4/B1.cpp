/*
 * @Date         : 2020-02-11 13:41:35
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
stack<char> s;
string str;
bool solve()
{
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        else {
            if (str[i] == ')' && s.top() == '(') {
                s.pop();
                continue;
            }
            if (str[i] == ']' && s.top() == '[') {
                s.pop();
                continue;
            }
            if (str[i] == '}' && s.top() == '{') {
                s.pop();
                continue;
            }
        }
    }
    if (s.empty())
        return 1;
    else
        return 0;
}
int main()
{
    cin >> str;
    if (solve())
        puts("Yes");
    else
        puts("No");
}