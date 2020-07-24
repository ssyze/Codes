#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 20;
const int inf = 0x3f3f3f3f;
int n, m, ans;
int s[maxn], v[maxn];

//s[i],v[i] 表示 i 层以上，表面积和体积的最小值之和
void init()
{
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 0; j < i; j++)
        {
            s[i] += (i - j) * (i - j);
            v[i] += (i - j) * (i - j) * (i - j);
        }
    }
}
/* 
*  V代表剩余的体积
*  M代表层数
*  R代表半径
*  H代表高度
*  sum代表面积
*/
void dfs(int V, int M, int R, int H, int sum)
{
    if (M == 0 && V == 0)
    {
        if (sum < ans)
            ans = sum;
        return;
    }
    if (v[M] > V)
        return;
    if (s[M] + sum > ans)
        return;
    int avgV = V / M;
    for (int i = R - 1; i >= M; i--)
    {
        for (int j = H - 1; j >= M; j--)
        {
            int curV = i * i * j;
            if(curV < avgV)
                break;
            if (curV > V)
                continue;
            int leftV = 0;
            for (int k = 1; k < m; k++)
                leftV += (i - k) * (i - k) * (j - k);
            if (V - curV > leftV)
                break;
            if (m == M)
                sum = i * i;
            dfs(V - curV, M - 1, i, j, sum + 2 * i * j);
        }
    }
}
int main()
{
    init();
    cin >> n >> m;
    ans = inf;
    dfs(n, m, sqrt((double)n) + 1, n + 1, 0);
    printf("%d\n", ans == inf ? 0 : ans);
}