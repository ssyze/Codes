/*
 * @Date         : 2020-07-12 01:08:09
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int n, k, t, a, b;
vector<int> A, B, T;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t >> a >> b;
        if (a && b)
            T.push_back(t);
        else if (a)
            A.push_back(t);
        else if (b)
            B.push_back(t);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(T.begin(), T.end());
    // cout << A.size() << ' ' << B.size() << ' ' << T.size() << endl;
    int sum = 0, pos = k;
    if (A.size() + T.size() < k || B.size() + T.size() < k) {
        cout << -1 << endl;
        return 0;
    }
    else if (A.size() + T.size() == k && B.size() + T.size() == k) {
        for (auto& x : A) sum += x;
        for (auto& x : B) sum += x;
        for (auto& x : T) sum += x;
        cout << sum << endl;
        return 0;
    }
    else if (A.size() + T.size() == k) {
        for (auto& x : A) sum += x;
        for (auto& x : T) sum += x;
        for (int i = 0; i < (k - T.size()); i++) sum += B[i];
        cout << sum << endl;
        return 0;
    }
    else if (B.size() + T.size() == k) {
        for (auto& x : B) sum += x;
        for (auto& x : T) sum += x;
        for (int i = 0; i < (k - T.size()); i++) sum += A[i];
        cout << sum << endl;
        return 0;
    }
    // cout << 1 << endl;
    int i = 0, j = 0, num = 0;
    for (int p = min(k - 1, int(T.size()) - 1);
         i < min(k, int(A.size())) && j < min(k, int(B.size())); i++, j++) {
        if (p < 0) break;
        if (A[i] + B[j] <= T[p]) {
            sum += (A[i] + B[j]);
            p--;
            pos--;
            num++;
        }
        else
            break;
    }
    // cout << i << ' ' << j << ' ' << num << endl;
    for (int i = 0; i < min(pos, int(T.size())); i++) sum += T[i], num++;
    while (num != k) {
        sum += A[i++];
        sum += B[j++];
        num++;
    }
    cout << sum << endl;
}