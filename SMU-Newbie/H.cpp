#include <bits/stdc++.h>
using namespace std;
int a[12] = { 0, 1, 0, 0, 0, 1, 5, 33, 245, 2053, 19137, 196705 };
int t, n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        cout << a[n] << endl;
    }
}