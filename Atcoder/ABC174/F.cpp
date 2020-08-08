/*
 * @Date         : 2020-08-09 01:21:15
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;

int a[maxn << 1], tree[maxn << 1], n, q;

inline int lowbit(int x) { return x & -x; }

void add(int pos, int val)
{
    while (pos <= n) tree[pos] += val, pos += lowbit(pos);
}

int query(int pos)
{
    int res = 0;
    while (pos > 0) res += tree[pos], pos -= lowbit(pos);
    return res;
}