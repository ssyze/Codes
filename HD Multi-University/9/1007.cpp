#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int t, n, q, x, y, op, a[maxn];
struct Splay {

    struct Node {
        int father, childs[2], key, cnt, sz, sum, minv;
        void init() { father = childs[0] = childs[1] = key = cnt = sz = 0; }
        void init(int fa, int lc, int rc, int k, int c, int s)
        {
            father = fa;
            childs[0] = lc;
            childs[1] = rc;
            key = k;
            cnt = c;
            sz = s;
        }
    } tre[maxn];

    int tot, root;
    void init() { tot = root = 0; }

    inline bool judge(int x) { return tre[tre[x].father].childs[1] == x; }

    inline void update(int x)
    {
        if (x) {
            tre[x].sz = tre[x].cnt;
            tre[x].sum = tre[x].minv = tre[x].key;
            if (tre[x].childs[0])
                tre[x].sz += tre[tre[x].childs[0]].sz, tre[x].sum += tre[tre[x].childs[0]].sum,
                    tre[x].minv = min(tre[x].minv, tre[tre[x].childs[0]].minv);
            if (tre[x].childs[1])
                tre[x].sz += tre[tre[x].childs[0]].sz, tre[x].sum += tre[tre[x].childs[1]].sum,
                    tre[x].minv = min(tre[x].minv, tre[tre[x].childs[1]].minv);
        }
    }

    inline void rotate(int x)
    {
        int y = tre[x].father, z = tre[y].father, k = judge(x);
        tre[y].childs[k] = tre[x].childs[!k];
        tre[tre[x].childs[!k]].father = y;
        tre[x].childs[!k] = y;
        tre[y].father = x;
        tre[z].childs[tre[z].childs[1] == y] = x;
        tre[x].father = z;
        update(y);
    }

    void splay(int x, int goal)
    {
        for (int father; (father = tre[x].father) != goal; rotate(x))
            if (tre[father].father != goal) rotate(judge(x) == judge(father) ? father : x);
        if (goal == 0) root = x;
    }

    void insert(int x)
    {
        if (root == 0) {
            tre[++tot].init(0, 0, 0, x, 1, 1);
            root = tot;
            return;
        }
        int now = root, father = 0;
        while (1) {
            if (tre[now].key == x) {
                tre[now].cnt++;
                update(now), update(father);
                splay(now, 0);
                break;
            }
            father = now;
            if (x > tre[now].key)
                now = tre[now].childs[1];
            else
                now = tre[now].childs[0];

            if (now == 0) {
                tre[++tot].init(father, 0, 0, x, 1, 1);
                if (x > tre[father].key)
                    tre[father].childs[1] = tot;
                else
                    tre[father].childs[0] = tot;
                update(father);
                splay(tot, 0);
                break;
            }
        }
    }

    int pre()
    {
        int now = tre[root].childs[0];
        while (tre[now].childs[1]) now = tre[now].childs[1];
        return now;
    }

    int next()
    {
        int now = tre[root].childs[1];
        while (tre[now].childs[0]) now = tre[now].childs[0];
        return now;
    }

    int rnk(int x)
    { /// 找x的排名
        int now = root, ans = 0;
        while (1) {
            if (x < tre[now].key)
                now = tre[now].childs[0];
            else {
                if (tre[now].childs[0]) ans += tre[tre[now].childs[0]].sz;
                if (x == tre[now].key) {
                    splay(now, 0);
                    return ans + 1;
                }
                ans += tre[now].cnt;
                now = tre[now].childs[1];
            }
        }
    }

    int kth(int x)
    { /// 找排名为x的数字
        int now = root;
        while (1) {
            if (tre[now].childs[0] && x <= tre[tre[now].childs[0]].sz)
                now = tre[now].childs[0];
            else {
                int lchild = tre[now].childs[0], sum = tre[now].cnt;
                if (lchild) sum += tre[lchild].sz;
                if (x <= sum) return tre[now].key;
                x -= sum;
                now = tre[now].childs[1];
            }
        }
    }

    void del(int x)
    {
        find(x);
        if (tre[root].cnt > 1) {
            tre[root].cnt--;
            update(root);
            return;
        }
        if (!tre[root].childs[0] && !tre[root].childs[1]) {
            tre[root].init();
            root = 0;
            return;
        }
        if (!tre[root].childs[0]) {
            int old_root = root;
            root = tre[root].childs[1];
            tre[root].father = 0;
            tre[old_root].init();
            return;
        }
        if (!tre[root].childs[1]) {
            int old_root = root;
            root = tre[root].childs[0];
            tre[root].father = 0;
            tre[old_root].init();
            return;
        }
        int pre_node = pre(), old_root = root;
        splay(pre_node, 0);
        tre[root].childs[1] = tre[old_root].childs[1];
        tre[tre[old_root].childs[1]].father = root;
        tre[old_root].init();
        update(root);
    }

    bool find(int x)
    {
        int now = root;
        while (1) {
            if (now == 0) return 0;
            if (x == tre[now].key) {
                splay(now, 0);
                return 1;
            }
            if (x > tre[now].key)
                now = tre[now].childs[1];
            else
                now = tre[now].childs[0];
        }
    }
    int fnd(int r, int v)
    {
        int x = rnk(r);
        cout << x << endl;
        cout << kth(x) << endl;
        if (tre[x].key < v) return r;
        splay(x, 0);
        int y = tre[x].childs[0];
        int res = 0;
        while (y) {
            if (tre[y].childs[1] && tre[tre[y].childs[1]].minv < v)
                res += tre[tre[y].childs[1]].sz + 1, y = tre[y].childs[1];
            else if (tre[y].minv < v)
                return res + tre[tre[y].childs[0]].sz + 1;
            else if (tre[y].childs[0] && tre[tre[y].childs[0]].minv < v)
                y = tre[y].childs[0];
            else
                return 0;
        }
        return 0;
    }
} S;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        S.init();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            S.insert(a[i]);
        }
        S.splay(2, 0);
        cout << "*" << endl;
        cout << S.root << endl;
        cout << endl;
    }
}