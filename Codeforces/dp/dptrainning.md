---
title: Codeforces dp训练总结
date: 2020-04-11 15:29:51
tags:
- Codeforces
- dp
---

# 1.106C Buns

[链接](https://codeforces.com/problemset/problem/106/C)

## 题意：

有 $m$ 种面包，开始有 $n$ 克面粉，每种面包的原料 $a_{i}$ ，每种面包需要 $b_{i}$ 原料和 $c_{i}$ 面粉，能够赚到 $d_{i}$ 钱，同时还可以制造只需要 $c_{0}$ 面粉能够赚到 $d_{0}$ 钱的面包，问最多能赚到多少钱

## 题解：

裸的多重背包问题，有的原料和需要的原料可以看作每种物品有多少个，$c_{i}$为cost，$d_{i}$为weight，背包容量为n

好像是唯一一道该系列里被我秒了的题

## 代码：

```c++
/*
 * @Date         : 2020-04-05 17:29:09
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[15], b[15], c[15], d[15], dp[1005], amount[15];

void ZeroOnePack(int cost, int weight)
{
    for (int i = n; i >= cost; i--)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}

void CompletePack(int cost, int weight)
{
    for (int i = cost; i <= n; i++)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}

void MultiplePack(int cost, int weight, int amount)
{
    if (cost * amount >= n)
        CompletePack(cost, weight);
    else {
        int k = 1;
        while (k < amount) {
            ZeroOnePack(k * cost, k * weight);
            amount -= k;
            k <<= 1;
        }
        ZeroOnePack(amount * cost, amount * weight);
    }
}

int main()
{
    cin >> n >> m >> c[0] >> d[0];
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        amount[i] = a[i] / b[i];
    }
    amount[0] = n / c[0];
    for (int i = 0; i <= m; i++) {
        MultiplePack(c[i], d[i], amount[i]);
    }
    cout << dp[n] << endl;
}
```

# 2.431C k-Tree

[链接](https://codeforces.com/problemset/problem/431/C)

## 题意：

定义k树：每个节点有k个孩子，权值分别为$1...k$，树高无限。求k树权值和为n且至少有一条边权值大于d的路径数

## 题解：

定义$dp[i][j	]$为权值和为 $i$ 是否存在大于d的路径的方案数，如果存在 $j =1$，否则$j = 0$

遍历每个点，那么可以得到状态转移为

若当前边 > d，则

$dp[i][1] = (dp[i][1] + dp[i - j][0])\%mod$

$dp[i][1]=(dp[i][1] + dp[i-j][1])\%mod$

当前边 <= d， 则

$dp[i][0] = (dp[i][0] + dp[i-j][0])\%mod$

$dp[i][1]=(dp[i][1]+dp[i-j][1])\%mod$

写的时候又忘了怎么dp了，dp也太难了

## 代码：

```c++
/*
 * @Date         : 2020-04-03 15:59:03
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int mod = 1e9 + 7;
int dp[maxn][2];
int n, k, d;
int main()
{
    dp[0][1] = 0;
    dp[0][0] = 1;
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 0;
        for (int j = 1; j <= k; j++) {
            if (j < d && i - j >= 0) {
                dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
            }
            else if (j >= d && i - j >= 0) {
                dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
            }
        }
    }
    cout << dp[n][1] % mod << endl;
}
```

# 3.455C Boredom

[链接](https://codeforces.com/problemset/problem/455/A)

## 题意：

给定n个数字，每次操作可以删除一个数字，同时会删除所有$a_{k}-1$与$a_{k}+1$的数字，同时会又会得到$a_{k}$分，求最多能得到多少分

## 题解：

先存每个数字有多少个，由于$1 \leq a_{i} \leq 10^5$，还是存的下的

设$dp[i]$为到 $i$ 为止最大总分，则$dp[i] = max(dp[i-1],dp[i-2] + i\times cnt[i])$

## 代码：

```c++
/*
 * @Date         : 2020-04-03 14:35:09
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll dp[maxn];
ll cnt[maxn], n;
int main()
{
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    dp[1] = cnt[1];
    for (ll i = 2; i < maxn; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
    }
    cout << dp[maxn - 1] << endl;
}
```

# 4.607A Chain Reaction

[链接](https://codeforces.com/problemset/problem/607/A)

## 题意：

给定n个灯塔所在坐标和power level，点亮任意灯塔会毁掉其左边power level范围内的灯塔，同时起初可以在最右灯塔的右边任意位置放一个任意power level的灯塔并点亮他，求最少毁灭多少灯塔

## 题解：

最少毁灭多少灯塔不好求，但我们可以求最多可以点亮多少灯塔，$n - ans$即可

令$dp[i]$为坐标为 $i$ 最多能点亮多少灯塔

由于 $1 \leq a_{i}\leq10^6$，因此遍历所有的坐标可以得到

```python
if i == a[j]:
	dp[i] = dp[i - b[j] - 1] + 1
else:
    dp[i] = dp[i - 1]
```

## 代码：

```c++
/*
 * @Date         : 2020-04-07 13:39:57
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
pair<int, int> p[maxn];
int dp[maxn];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n, [&](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
    dp[p[0].first] = 1;
    for (int i = p[0].first + 1, j = 1; i <= p[n - 1].first; i++) {
        if (i == p[j].first) {
            if (i - p[j].second - 1 < 0)
                dp[i] = 1;
            else
                dp[i] = dp[i - p[j].second - 1] + 1;
            j++;
        }
        else
            dp[i] = dp[i - 1];
    }
    int ans = -1;
    for (auto& x : dp) {
        //cout << x << endl;
        ans = max(ans, x);
    }
    cout << n - ans << endl;
}
```

# 5.706C Hard problem

[链接](https://codeforces.com/problemset/problem/706/C)

## 题意：

给定n个字符串，翻转任意字符串需要$a_{i}$的能量，求能否进行任意翻转使n个字符串按字典序排序，输出最小的能量消耗，若不能输出-1

## 题解：

$dp[i][0]$为第$i$个字符串不翻转可以字典序排序的最小能量

$dp[i][1]$为第$i$个字符串翻转后可以字典序排序的最小能量

$s[i]$存储原字符串，$r[i]$存储翻转后的字符串

利用四个if转移即可

## 代码：

```c++
/*
 * @Date         : 2020-04-05 14:52:45
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
string s[maxn], r[maxn];
ll n, c[maxn], dp[maxn][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for (int i = 1; i < n; i++) {
        if (s[i] >= s[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (s[i] >= r[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (r[i] >= s[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        if (r[i] >= r[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
    }
    ll ans = min(dp[n - 1][1], dp[n - 1][0]);
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
```

# 6.977F Consecutive Subsequence

[链接](https://codeforces.com/problemset/problem/977/F)

## 题意：

给定n个数字，求最长的连续子序列，连续定义为$[x, x + 1, x+2,……,x+k-1]$，并输出下标

## 题解：

定义$dp[i]$为最后一项为 $i$ 的最长连续子序列，可以利用map来存这个东西

因此$dp[a_{i}] = dp[a_{i}-1]+1$

`if len < dp[a[i]]`

`len = dp[a[i]], ans = i;`

最后从尾遍历一遍序列，把下标存入vector输出

## 代码：

```c++
/*
 * @Date         : 2020-04-12 17:52:47
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, a[maxn];
map<int, int> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0, len = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        dp[x] = max(dp[x], dp[x - 1] + 1);
        if (len < dp[x]) {
            len = dp[x];
            ans = x;
        }
    }
    vector<int> v;
    for (int i = n; i >= 1; i--) {
        if (a[i] == ans) {
            v.push_back(i);
            ans--;
        }
    }
    cout << len << endl;
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << ' ';
    cout << endl;
}
```

# 7.1096D Easy Problem

[链接](https://codeforces.com/problemset/problem/1096/D)

## 题意：

给定字符串，删除字符需要代价$a_{i}$，需要字符串中不出现"hard"的子序列，求最小代价

## 题解：

设$dp[i][j]$表示到 $i$ 为止，匹配了 hard 的多少前缀的最小代价

即$dp[i][0]$表示到 $i$ 为止没有匹配 h，$dp[i][1]$表示匹配了h，$dp[i][2]$表示匹配了ha

对于 $i$ 这个字符，有两种处理方式，删除或保留

删除的情况即前 $i - 1$ 位已经匹配了 $j$ 位前缀

保留的情况即前 $i - 1$ 位只匹配了 $j - 1$ 位前缀

因此转移方程为：

$dp[i][j] = min(dp[i-1][j-1], dp[i-1][j] + a[i])$

## 代码：

```c++
/*
 * @Date         : 2020-04-10 16:19:49
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll n, a[maxn], dp[maxn][5];
char s[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s + 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    string t = " hard";
    for (int i = 1; i <= 4; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            if (s[i] != t[j]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + a[i]);
            }
        }
    }
    cout << dp[n][4] << endl;
}
```

# 8.1109A Sasha and a Bit of Relax

[链接](https://codeforces.com/problemset/problem/1109/A)

## 题意：

给定$n$个数字，定义$mid=\frac{l+r-1}{2}$，问能找到几对$(l, r)$，使$r-l+1$为偶数，且$a_{l}⊕a{l+1}⊕…⊕a_{mid}=a_{mid+1}⊕a_{mid+2}⊕…⊕a_{r}$

## 题解：

很容易想到异或前缀和，毕竟$a_{1}\bigoplus a_{2} \bigoplus a_{2} = a_{1}$

当然$O(n^2)$的暴力是不可能过的，毕竟$2\leq n\leq 3 \cdot 10^5$（因为试过了

由于区间长度固定为偶数，考虑$dp[0/1][i]$

$dp[0][i]$表示下标为偶数，异或前缀和为 $i$ 的个数

$dp[1][i]$表示下标为奇数，异或前缀和为 $i$ 的个数

那么先$memset(dp,0,sizeof(dp))$

做完异或前缀和后，$ans += dp[i\&1][sum[i]]$输出就完事了

## 代码：

```c++
/*
 * @Date         : 2020-04-10 17:49:52
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
typedef long long ll;
int sum[maxn], a[maxn], n;
ll cnt[2][1 << 21];
// cnt[i][j] i表示是奇数还是偶数 j表示异或前缀和
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] ^ a[i];
    cnt[0][0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[i & 1][sum[i]];
        cnt[i & 1][sum[i]]++;
    }
    printf("%lld\n", ans);
}
```

# 9.1221D Make The Fence Great Again

[链接](https://codeforces.com/problemset/problem/1221/D)

## 题意：

给定$n$块板及其高度，可以花费$b_{i}$将第$i$块板提高1，求使他们great的最小花费

great的定义为，从$2$到$n$，不存在$a_{i-1}=a_{i}$

## 题解：

可以想到，对于任意一块板而言，最多只需要提高2，一定可以使得其与相邻的两块板高度不相等

考虑$dp[i][j]$表示对第$i$块板提高$j$，使前$i$块板great的最小代价，因此可以得到

```c++
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= 2; j++) {
		for (int k = 0; k <= 2; k++) {
			if (a[i] + j = a[i - 1] + k) {
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
			}
		}
	}
}
```

## 代码：

```c++
/*
 * @Date         : 2020-04-09 17:43:36
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll dp[maxn][3];
int n, q, a[maxn], b[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            dp[i][0] = dp[i][1] = dp[i][2] = inf;
        }
        dp[0][0] = dp[0][1] = dp[0][2] = dp[1][0] = 0;
        dp[1][1] = b[1];
        dp[1][2] = 2 * b[1];
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (a[i] + j != a[i - 1] + k) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
                    }
                }
            }
        }
        cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
    }
}
```

# 10.1239A Ivan the Fool and the Probability Theory

[链接](https://codeforces.com/problemset/problem/1239/A)

## 题意：

给定矩形的长宽，对矩形进行黑白涂色，对每个格子最多只能有一个相邻格有相同的颜色，求涂色方案数

## 题解：

这个长的更像数学题，所以用数学的角度来分析一下这个问题

先思考只有一行的情况，定义$dp[i][j]$，$dp[i][0]$为长度为 $i$ ，且第 $i$ 位为白色，$dp[i][1]$为黑色

那么可以想到，转移方程应该为

$dp[i][0] = dp[i-1][1] + dp[i-2][1]\quad\quad ①$

$dp[i-1][1]$为 ...黑白，$dp[i-2][1]$为...黑白白

同理：$dp[i][1] = dp[i-1][0]+dp[i-2][0]\quad\quad ②$

①+②可得$dp[i][0]+dp[i][1]=dp[i-1][1]+dp[i-1][0]+dp[i-2][1]+dp[i-2][0]$

都长成这个样子了，可以简化为$dp[i]=dp[i-1]+dp[i-2]$

再思考多行的情况：

可以想到对于任意两行而言，他们必然是完全相同或完全相反的

完全相反的情况一定是前一行存在两个相同颜色相连的情况，这样第一行有多少种存在两个相邻的就决定了整个矩形的分布

若前一行没有下相同颜色相连，那么必然每一行黑白是交替的情况，那么这时的种类由第一列的种类确定

因此总的数量=第一列情况+第一行情况-2（第一行黑白交替两种）

## 代码：

```c++
/*
 * @Date         : 2020-04-09 17:27:52
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
ll n, m, dp[maxn];
int main()
{
    cin >> n >> m;
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i <= max(n, m); i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    cout << (dp[n] + dp[m] - 2) % mod << endl;
}
```

