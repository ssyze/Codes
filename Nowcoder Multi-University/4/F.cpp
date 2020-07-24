/*
 * @Date         : 2020-07-20 18:53:34
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t, ac, bc, ad, bd;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> ac >> ad >> bc >> bd;
        int l = max(ac, max(ad, max(bc, bd)));
        if (l == ac || l == bd)
            cout << "AB//DC" << '\n';
        else
            cout << "AB//CD" << '\n';
    }
}