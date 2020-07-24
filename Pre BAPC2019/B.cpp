/*
 * @Date         : 2020-03-14 13:55:31
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
string s;
long long ans, tmp;
int to_num(string a)
{
    int sum = 0, e = 1;
    for (int i = a.length() - 1; i >= 0; i--) {
        sum += (a[i] - '0') * e;
        e *= 10;
    }
    return sum;
}
int main()
{
    int dep = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "(") {
            dep++;
            if (dep & 1) {
            }
        }
    }
}