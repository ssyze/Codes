/*
 * @Date         : 2020-05-23 12:59:01
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, m, time1, time2;
pair<int, int> qq[16], cc[16];
int vis1[16], vis2[16];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        char a = s[0], b = s[1];
        int x = a - 'A' + 1, y = b - '0';
        qq[i].first = x, qq[i].second = y;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        char a = s[0], b = s[1];
        int x = a - 'A' + 1, y = b - '0';
        cc[i].first = x, cc[i].second = y;
    }
    sort(qq, qq + n);
    sort(cc, cc + n);
    for (int i = 0; i < n - 1; i++) {
        if (vis1[i])
            continue;
        time1++;
        int num = 0, mx = -1, pos = -1;
        vector<int> s[16];
        for (int j = i + 1; j < n; j++) {
            if (vis1[j])
                continue;
            int sum = 0;
            pair<int, int> cur, nxt;
            cur.first = qq[i].first - qq[j].first, cur.second = qq[i].second - qq[j].second;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j || vis1[k])
                    continue;
                nxt.first = qq[k].first - qq[j].first, nxt.second = qq[k].second - qq[j].second;
                if (nxt.first * cur.second - nxt.second * cur.first == 0) {
                    sum++;
                    s[num].push_back(k);
                }
            }
            if (sum > mx) {
                mx = sum;
                pos = j;
            }
            num++;
        }
        vis1[i] = 1, vis1[pos] = 1;
        for (auto& x : s[pos - 1]) {
            vis1[x] = 1;
        }
    }
    int sums = 0;
    for (int i = 0; i < n; i++) {
        if (!vis1[i])
            sums++;
    }
    time1 += (sums + 1) / 2;
    for (int i = 0; i < m - 1; i++) {
        if (vis2[i])
            continue;
        time2++;
        int num = 0, mx = -1, pos = -1;
        vector<int> s[16];
        for (int j = i + 1; j < m; j++) {
            //cout << j << endl;
            if (vis2[j])
                continue;
            int sum = 0;
            pair<int, int> cur, nxt;
            cur.first = cc[i].first - cc[j].first, cur.second = cc[i].second - cc[j].second;
            for (int k = 0; k < m; k++) {
                if (k == i || k == j || vis2[k])
                    continue;
                nxt.first = cc[k].first - cc[j].first, nxt.second = cc[k].second - cc[j].second;
                if (nxt.first * cur.second - nxt.second * cur.first == 0) {
                    sum++;
                    s[num].push_back(k);
                }
            }
            if (sum > mx) {
                mx = sum;
                pos = j;
            }
            num++;
        }
        vis2[i] = 1, vis2[pos] = 1;
        for (auto& x : s[pos - 1]) {
            vis2[x] = 1;
        }
    }
    int sumss = 0;
    for (int i = 0; i < m; i++)
        if (!vis2[i])
            sumss++;
    time2 += (sumss + 1) / 2;
    cout << time1 << ' ' << time2 << endl;
    if (time1 <= time2)
        cout << "Cuber QQ" << endl;
    else
        cout << "Quber CC" << endl;
}