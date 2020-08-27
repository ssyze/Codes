/*
 * @Date         : 2020-07-27 00:52:06
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
unsigned long long sum;
mt19937 rnd(time(0));
int main()
{
    for (int i = 0; i < 1e9 + 5; i++) sum += i;
    cout << sum << endl;
    cout << (double)clock() / CLOCKS_PER_SEC << endl;
}