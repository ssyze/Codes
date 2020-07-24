/*
 * @Date         : 2019-12-01 19:26:08
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    mt19937 rnd(time(0));
    int n = rnd() % 8 + 1;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        int tmp = rnd() % n + 1;
        cout << tmp << endl;
    }
}