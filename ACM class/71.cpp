#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            q.push(x);
        }
        int t = n - 1, ans = 0;
        while (t--)
        {
            int tmp1, tmp2, tmp;
            tmp1 = q.top();
            q.pop();
            tmp2 = q.top();
            q.pop();
            tmp = tmp1 + tmp2;
            ans += tmp;
            q.push(tmp);
        }
        cout << ans << endl;
    }
}