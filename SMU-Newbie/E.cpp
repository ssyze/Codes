#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main()
{
    cin >> n >> m >> k;
    if (n == 1 && m == 1)
        cout << "Beautiful flowers!" << endl;
    else if (k >= 2)
        cout << "Beautiful flowers!" << endl;
    else
        cout << "Oh! My poor HJ!" << endl;
}