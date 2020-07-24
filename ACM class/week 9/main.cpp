/*
 * @Date         : 2020-03-18 17:54:41
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int a[16] = { 20, 67, 64, 2, 81, 99, 10, 44, 71, 93, 41, 73, 65, 86, 95, 69 };
int main()
{
    for (int i = 0; i < 1 << 16; i++) {
        int tmp = i, num = 0, sum = 0;
        vector<int> b;
        while (tmp) {
            if (tmp & 1) {
                sum += a[num];
                b.push_back(a[num]);
            }
            tmp >>= 1;
            num++;
        }
        if (sum == 860) {
            for (auto& x : b)
                cout << x << endl;
            cout << endl;
        }
        b.clear();
    }
}