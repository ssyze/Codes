/*
 * @Date         : 2020-02-13 13:50:13
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    cin >> n;
    if (n != 1 && (n & n - 1) == 0)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}