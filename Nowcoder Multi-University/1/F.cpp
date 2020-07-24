/*
 * @Date         : 2020-07-12 12:19:51
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
string a, b;
int main()
{
    while (cin >> a >> b) {
        if (a == b) {
            cout << "=\n";
            continue;
        }
        int tmp1 = 1, tmp2 = 1;
        for (int i = 1; i < a.length(); i++)
            if (a[i] != a[i - 1]) {
                tmp1 = 0;
                break;
            }
        for (int i = 1; i < b.length(); i++)
            if (b[i] != b[i - 1]) {
                tmp2 = 0;
                break;
            }
        if (tmp1 && tmp2 && a[0] == b[0]) {
            cout << "=\n";
            continue;
        }
        int i = 0, j = 0, flag = 0, t = 0, lena = a.length(), lenb = b.length();
        while (1) {
            if (a[i] < b[j]) {
                flag = 1;
                break;
            }
            if (a[i] > b[j]) {
                flag = 2;
                break;
            }
            t++;
            i++;
            j++;
            if (i == lena) i = 0;
            if (j == lenb) j = 0;
            if (t >= 2e5 + 5) break;
        }
        if (flag == 1)
            cout << "<\n";
        else if (flag == 2)
            cout << ">\n";
        else
            cout << "=\n";
    }
}