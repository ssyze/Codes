/*
 * @Date         : 2020-03-28 18:24:24
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t, Case;
int main()
{
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int flag = 0;
        for (ll i = 2; i * i <= 1000000000; i++) {
            if (n % (i * i) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag)
            printf("Case %d: No\n", ++Case);
        else
            printf("Case %d: Yes\n", ++Case);
    }
}
