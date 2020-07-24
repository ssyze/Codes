/*
 * @Date         : 2020-03-28 17:55:36
 * @Author       : ssyze
 * @Description  : 
 * 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 100000007;
struct matrix {
    ll a[11][11]; //begin with 1
    int r, c;
    matrix(int n, int m)
        : r(n)
        , c(m)
    {
        memset(a, 0, sizeof(a));
    }
    ll* operator[](int x) { return a[x]; }
    friend matrix operator*(matrix A, matrix B)
    {
        matrix C(A.r, B.c);
        for (int i = 1; i <= A.r; i++)
            for (int j = 1; j <= B.c; j++)
                for (int k = 1; k <= A.c; k++) {
                    C[i][j] += (A[i][k] * B[k][j]) % mod;
                    C[i][j] += mod;
                    C[i][j] %= mod;
                }
        return C;
    }
};

matrix qpow(matrix A, ll m) //方阵A的m次幂
{
    matrix ans(A.r, A.c);
    for (int i = 1; i <= A.r; i++)
        ans.a[i][i] = 1; //单位矩阵
    while (m) {
        if (m & 1)
            ans = ans * A;
        A = A * A;
        m >>= 1;
    }
    return ans;
}

int main()
{
    ll n;
    while (cin >> n) {
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n == 2) {
            cout << 2 << endl;
            continue;
        }
        matrix A(3, 3);
        A[1][1] = 2 % mod;
        A[1][2] = 1 % mod;
        A[1][3] = 1 % mod;
        A[2][1] = 1 % mod;
        A[2][2] = 0 % mod;
        A[2][3] = 0 % mod;
        A[3][1] = 0 % mod;
        A[3][2] = 0 % mod;
        A[3][3] = 1 % mod;
        matrix X2(3, 1);
        X2[1][1] = 2 % mod;
        X2[2][1] = 1 % mod;
        X2[3][1] = 1 % mod;
        matrix Xn = qpow(A, n - 2) * X2;
        printf("%lld\n", Xn[1][1] % mod);
    }
}