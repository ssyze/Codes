/*
 * @Date         : 2019-12-28 14:28:48
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 11;
    int a[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int res = 0;
    do {
        int flag = 1;
        for (int i = 1; i < n - 1; i++) {
            if (abs(a[i] - a[i - 1]) == 1 || abs(a[i] - a[i + 1]) == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            if (abs(a[0] - a[1]) != 1 && abs(a[0] - a[n - 1]) != 1 && abs(a[n - 1] - a[n - 2]) != 1) {
                res++;
            }
        }
    } while (next_permutation(a, a + n));
    //cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
    cout << res / (2 * n) << endl;
    return 0;
}