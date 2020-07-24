/*
 * @Date         : 2020-02-08 14:29:17
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int a[maxn];
int n, node_num;
struct node {
    int id, fa, rc, lc;
};
vector<node> v;
bool cmp(node a, node b)
{
    return a.id < b.id;
}
int main()
{
    cin >> n;
    for (int i = 0; i < maxn; i++)
        a[i] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != -1)
            node_num++;
    }
    printf("The size of the tree is %d\n", node_num);
    printf("Node %d is the root node of the tree\n", a[1]);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != -1) {
            node cur;
            cur.id = a[i];
            cur.fa = a[i / 2];
            cur.lc = a[i * 2];
            cur.rc = a[i * 2 + 1];
            v.push_back(cur);
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto& x : v) {
        printf("The father of node %d is %d, the left child is %d, and the right child is %d\n", x.id, x.fa, x.lc, x.rc);
    }
}