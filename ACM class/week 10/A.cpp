/*
 * @Date         : 2020-03-25 17:13:40
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 10007;
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
    ll d, k;
    while (cin >> d >> k) {
        int tmp = sqrt(d);
        if (tmp * tmp == d) {
            printf("No answer.\n");
            continue;
        }
        int x0, y0;
        for (int i = 1;; i++) {
            int tmp = sqrt(1 + d * i * i);
            if (tmp * tmp == (1 + d * i * i)) {
                x0 = tmp, y0 = i;
                break;
            }
        }
        matrix A(2, 2);
        A[1][1] = x0 % mod;
        A[1][2] = d * y0 % mod;
        A[2][1] = y0 % mod;
        A[2][2] = x0 % mod;
        matrix X2(2, 1);
        X2[1][1] = x0 % mod;
        X2[2][1] = y0 % mod;
        matrix Xn = qpow(A, k - 1) * X2;
        printf("%lld %lld\n", Xn[1][1] % mod, Xn[2][1] % mod);
    }
}