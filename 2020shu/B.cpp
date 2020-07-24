/*
 * @Date         : 2020-04-18 12:03:24
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct student {
    string a;
    int b;
    double c;
} s[maxn];
bool cmp(student a, student b)
{
    if (a.a == b.a && a.c == b.c)
        return a.b < b.b;
    if (a.a == b.a)
        return a.c > b.c;
    return a.a > b.a;
}
int n;
int main()
{
    cin >> n;
    vector<student> v;
    for (int i = 0; i < n; i++) {
        cin >> s[i].a >> s[i].b >> s[i].c;
        if (s[i].c >= 38.0)
            v.push_back(s[i]);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].a << ' ' << v[i].b << ' ';
        printf("%.1f\n", v[i].c);
    }
}