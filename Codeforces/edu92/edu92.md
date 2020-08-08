一场前四题都是暴力（第五题直接不会，看题解还理解了好久

<!--more-->

<!--index-menu-->

# A. LCM Problem

## 题意：

给定$l,r$，找出$Lcm(x,y)$,满足$l \leq x, \ y, \ Lcm(x,y) \leq r$

## 题解：

显然输出$l, 2*l$

## 代码：

```cpp
/*
 * @Date         : 2020-07-29 22:36:21
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t, l, r;
int main()
{
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int x = l;
        if (2 * l > r)
            cout << -1 << ' ' << -1 << endl;
        else
            cout << l << ' ' << 2 * l << endl;
    }
}
```

# B. Array Walk

## 题意：

给定序列，每个位置有个值，从左走到右，一共可以向左走$z$步，但不能连续两次向左走，求$\sum a[i]$

## 题解：

向左走的机会一定留给之前和最大的两个数，记录一下和最大的两个数的位置，判断一下走到$i$还能走多少步，向左的机会尽可能用在最大的位置上，若最后一步还能向左走那就加$a[i-1]$

## 代码：

```cpp
/*
 * @Date         : 2020-07-29 23:11:58
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n, k, z, a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> z;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int sum = a[1], mx = -1, sum1, ans = -1, pos = -1;
        for (int i = 2; i <= k + 1; i++) {
            if (a[i - 1] + a[i] > mx) {
                mx = a[i - 1] + a[i];
                pos = i;
            }
            sum += a[i];
            sum1 = sum;
            int tmp = k - i + 1, q = z;
            for (; tmp > 1 && q > 0; q--, tmp -= 2) {
                sum1 += a[pos - 1] + a[pos];
            }
            if (q && tmp) sum1 += a[i - 1];
            ans = max(ans, sum1);
        }
        ans = max(ans, sum);
        cout << ans << endl;
    }
}
```

# C. Good String

## 题意：

一个字符串，若头放到尾和尾放到头形成的两个串相同，那就good，求最少删多少字符能使串good

## 题解：

显然good的串应当是①由同一字符构成②由两种字符交替构成，且串长为偶数

那么暴力一下留下的应当是什么字符，判断一下要删多少字符就做完了

## 代码：

```cpp
/*
 * @Date         : 2020-07-30 00:03:12
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
pair<int, int> num[10];
int t;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 10; i++) {
            string tmp = "";
            for (int j = 0; j < s.length(); j++) {
                if (s[j] - '0' == i) tmp += s[j];
            }
            if (tmp == "") continue;
            if (tmp.length() == 1) {
                int len = s.length() - 1;
                ans = min(ans, len);
                continue;
            }
            int len = s.length() - tmp.length();
            ans = min(ans, len);
        }
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (i == k) continue;
                string tmp = "";
                for (int j = 0; j < s.length(); j++) {
                    if ((s[j] - '0') == i && tmp.length() == 0) tmp += s[j];
                    if ((s[j] - '0') == i && (tmp[tmp.length() - 1] - '0') == k) tmp += s[j];
                    if ((s[j] - '0') == k && (tmp[tmp.length() - 1] - '0') == i) tmp += s[j];
                }
                if (tmp == "") continue;
                if (tmp.length() == 1) {
                    int len = s.length() - 1;
                    ans = min(ans, len);
                    continue;
                }
                int len = s.length() - tmp.length();
                if (tmp.length() % 2 == 0) len--;
                ans = min(ans, len + 1);
            }
        }
        cout << ans << endl;
    }
}
```

# D. Segment Intersections

## 题意：

给定$n$个相同的$a$区间和$b$区间，每次可以将一个区间延长$1$，求最少多少次操作可以使这$n$个区间的交集$\ge k$

## 题解：

那么又显然可以分成两种，原本就有交集和原本无交集

有交集的情况下，前$n$个串每延长$1$个单位交集就$+1$，若全部延长完了还没到$k$，那么延长$2$个单位交集$+1$，暴力一下就做完了

无交集的情况下，可以枚举使前$i$个串产生交集的情况下，最少需要多少次操作，而前$i$个串的情况下的算法和有交集的情况相同，总是先把他们端点对齐然后算

$tips:$ 除法算需要多少对串全部对齐可能产生$\div0$的情况，直接用乘法判断操作次数更好

## 代码：

```cpp
/*
 * @Date         : 2020-07-31 22:45:56
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, k, l[2], r[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> l[0] >> r[0] >> l[1] >> r[1];
        if (l[0] > l[1]) {
            swap(l[0], l[1]);
            swap(r[0], r[1]);
        }
        ll ans = 0, sum = 0;
        if (r[0] < l[1]) {
            ll tmp = l[1] - r[0];
            if (r[1] - l[0] >= k) {
                cout << l[1] - r[0] + k << endl;
                continue;
            }
            ll ans = 0x3f3f3f3f3f3f3f3f;
            for (int i = 1; i <= n; i++) {
                ll s = tmp * i;
                ll tmp1 = r[1] - l[0];
                int ti = k / tmp1;
                if (ti >= i)
                    ans = min(ans, s + i * tmp1 + (k - tmp1 * i) * 2);
                else
                    ans = min(ans, s + ti * tmp1 + (k - ti * tmp1));
            }
            cout << ans << endl;
        }
        else {
            ll ans = 0, sum = n * (min(r[0], r[1]) - max(l[0], l[1]));
            k -= sum;
            if (k <= 0) {
                cout << ans << endl;
                continue;
            }
            sum = max(r[0], r[1]) - min(r[0], r[1]) + max(l[0], l[1]) - min(l[0], l[1]);
            if (sum == 0) {
                cout << k * 2 << endl;
                continue;
            }
            int ti = k / sum;
            if (ti < n) {
                cout << ans + k << endl;
                continue;
            }
            else {
                ans += sum * n;
                k -= sum * n;
                cout << ans + 2 * k << endl;
                continue;
            }
        }
    }
}
```

# E. Calendar Ambiguity

## 题意：

一年有$m$个月，每个月有$d$天，每周有$w$天，问存在多少对$(i,j)$，在一个星期的同一天，即$i$月$j$日与$j$月$i$日有相同的星期$X$

## 题解：

首先若$i$月$j$日与$j$月$i$日星期相同，必然满足以下等式
$$
(i-1)\cdot d + j \equiv (j-1)\cdot d + i \ \  mod\ w
$$
于是我们做一下等式变换可以得到这样的结果
$$
i\cdot d - d + j \equiv j \cdot d - d + i \ \ (mod \ w)
\\
i\cdot(d - 1) \equiv j\cdot(d -1) \ \ (mod \ w)
\\
(i-j)\cdot(d-1) \equiv 0 \ (mod\ w)
$$
于是若再令
$$
w^{'} = \frac{w}{gcd(d - 1, w)}
$$
只需$w^{'} \mid (i-j)$即可，如此我们就可以开始枚举了

不过还需要注意$i,j$ 的取值范围应是$mn = min(m, d)$，因为比如$m = 7, d = 10$，那么存在7月10日，但不存在10月7日

从$i = mn$开始枚举，那么$(i - j)$的取值范围是$[1,mn-1]$，因为$j$至少取$1$

可以得到如下：
$$
i = mn, ans+=\frac{mn-1}{w^{'}}
\\ i = mn - 1, ans+= \frac{mn -2}{w^{'}}
\\ \dots
\\i = w^{'}, ans+=\frac{w^{'}}{w^{'}}
$$
同时这些取值必然是阶梯状的，设$x = \frac{mn-1}{w^{'}}$，那么取值就会是$x\dots x-1 \dots x-2 \dots 2 \dots 1$

除$x$外的所有取值都是$w^{'}$个，只需要计算有多少个$x$就可以了

那么$x$有$(mn-1)\% w^{'} + 1$个，比如$mn-1=5,w^{'}=4$，那么值为$2$的就有$2$个，分别是$5,4$

把两个值求个和就好了于是$ans=((mn-1)\%x + 1)\cdot x + \frac{x\cdot (x - 1)\cdot w^{'}}{2}$

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, m, d, w;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> m >> d >> w;
        w /= __gcd(d - 1, w);
        ll mn = min(m, d) - 1;
        ll x = mn / w, y = mn % w + 1;
        cout << x * (x - 1) * w / 2 + x * y << '\n';
    }
}
```



