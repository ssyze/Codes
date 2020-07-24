/*
 * @Date         : 2020-07-14 17:49:04
 * @Author       : ssyze
 * @Description  :
 */
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5;
int n, k, a[maxn];
vector<int> mn, mx;
void getmx()
{
    deque<int> q;
    for (int i = 0; i < k; i++) {
        while (!q.empty() && a[i] >= a[q.back()]) q.pop_back();
        q.push_back(i);
    }
    mx.push_back(a[q.front()]);
    for (int i = k; i < n; i++) {
        while (!q.empty() && i - q.front() >= k) q.pop_front();
        while (!q.empty() && a[i] >= a[q.back()]) q.pop_back();
        q.push_back(i);
        mx.push_back(a[q.front()]);
    }
}
void getmn()
{
    deque<int> q;
    for (int i = 0; i < k; i++) {
        while (!q.empty() && a[i] <= a[q.back()]) q.pop_back();
        q.push_back(i);
    }
    mn.push_back(a[q.front()]);
    for (int i = k; i < n; i++) {
        while (!q.empty() && i - q.front() >= k) q.pop_front();
        while (!q.empty() && a[i] <= a[q.back()]) q.pop_back();
        q.push_back(i);
        mn.push_back(a[q.front()]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    getmn();
    getmx();
    for (int i = 0; i < mn.size() - 1; i++) cout << mn[i] << ' ';
    cout << mn[mn.size() - 1] << '\n';
    for (int i = 0; i < mx.size() - 1; i++) cout << mx[i] << ' ';
    cout << mx[mx.size() - 1] << '\n';
}