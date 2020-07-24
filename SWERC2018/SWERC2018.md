---
title: 2018-2019 ICPC Southwestern European Regional Programming Contest (SWERC 2018)
date: 2020-06-17 13:58:00
tags:
- 训练赛
categories:
- 题解
- 训练赛
---

$AC\quad 5/11 \quad in \quad 5h$

<!--more-->

# E.Rounding

solved by cjy. 1:45(+3)

## 题意：

给定$n$个地点，对$n[i]$有被选择的百分比，百分比是四舍五入后的结果，求四舍五入前，最大百分比和最小百分比分别为多少，保留两位小数，若不可能输出IMPOSSIBLE

## 题解：

对于已知的百分比来说，一定可以得到在此之前的最大和最小的百分比理论值是多少，即

$mx=min\{100,n[i]+0.49\}$

$mn=max\{0,n[i]-0.5\}$

接着算每一个地点的最小值可以这样处理：其他所有地点取最大的，得到$sum$，$100-sum$得到该地点可能的最小值，若该最小值大于$n[i]-0.5$那么最小值只能取该值，否则最小值为$n[i]-0.5$，因此可以$O(n)$得到所有地点的最小值

同理可以$O(n)$得到所有地点的最大值

tips:IMPOSSIBLE的情况为最小值相加大于100或最大值相加小于100（wa在这里牛的

## 代码：

```c++
/*
 * @Date         : 2020-06-16 19:40:35
 * @Author       : ssyze
 * @Description  :  
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
string s[maxn];
int n, a[maxn], mx[maxn], mn[maxn];
int main()
{
    //freopen("t.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> a[i];
        a[i] *= 100;
        mx[i] = a[i] + 49;
        mn[i] = a[i] - 50;
        if (a[i] == 10000)
            mx[i] -= 49;
        if (a[i] == 0)
            mn[i] = 0;
    }
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n; i++)
        sum1 += mx[i], sum2 += a[i], sum3 += mn[i];
    if (sum1 < 10000 || sum3 > 10000) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int tmp = sum1 - mx[i];
        //cout << tmp << endl;
        tmp = 10000 - tmp;
        if (a[i] != 0) {
            if (a[i] - tmp > 50)
                mn[i] = a[i] - 50;
            else
                mn[i] = tmp;
        } else {
            if (-tmp > 0)
                mn[i] = 0;
            else
                mn[i] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        int tmp = sum3 - mn[i];
        tmp = 10000 - tmp;
        if (a[i] != 10000) {
            if (a[i] - tmp < -49)
                mx[i] = a[i] + 49;
            else
                mx[i] = tmp;
        } else {
            if (tmp >= 10000)
                mx[i] = 10000;
            else
                mx[i] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << ' ';
        //cout << mx[i] << ' ' << mn[i] << endl;
        double mxx = double(mx[i]) / 100.0;
        double mnn = double(mn[i]) / 100.0;
        printf("%.2f %.2f\n", mnn, mxx);
    }
}
```

# D. Monument Tour

solved by syr&&hyq&&cjy 4:14(+9)

## 题意：

选择任意一条从左向右的路线，使经过所有地点后走过的路最小，经过任一地点只能在$x$坐标相同时，向上或向下经过，输出最短的路径长度

## 题解：

应该想到（我没有

对任意$x$坐标下将所有点视为一条直线，只考虑两个端点即可，在这种情况下，选择的路径应当在这些点的$y$坐标中点附近（官方题解为中位数

只要$O(n)$得到从某个$y$坐标出发的点走过的长度，然后在中点的左右算个200次取最小值就做完了

## 代码：

```c++
/*
 * @Date         : 2020-06-16 22:38:47
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
pair<int, int> p[maxn];
vector<pair<int, int>> point;
int x, y, n;
ll Sum(int pos)
{
    ll ans = 0;
    for (int i = 0; i < point.size(); i++) {
        if (point[i].first == point[i + 1].first) {
            if (point[i].second <= pos && point[i + 1].second > pos)
                ans = ans + 2 * (pos - point[i].second) + 2 * (point[i + 1].second - pos);
            else if (point[i].second >= pos)
                ans += 2 * (point[i + 1].second - pos);
            else
                ans += 2 * (pos - point[i].second);
            i++;
        } else
            ans += 2 * abs(point[i].second - pos);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    int k = unique(p, p + n) - p;
    for (int i = 0; i < k;) {
        point.push_back({ p[i].first, p[i].second });
        int j = i + 1;
        while (p[j].first == p[i].first)
            j++;
        --j;
        if (j != i)
            point.push_back({ p[j].first, p[j].second });
        i = j + 1;
    }
    ll sum = 0, num = 0;
    for (auto& x : point)
        sum += x.second;
    int pos = sum / point.size();
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = pos - 100; i <= pos + 100; i++) {
        if (i < 0 || i >= y)
            continue;
        ans = min(ans, Sum(i));
    }
    cout << ans + x - 1 << endl;
}
```

