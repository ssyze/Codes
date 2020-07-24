/*
 * @Date         : 2020-05-23 14:35:28
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
typedef unsigned long long ull;
const int maxn = 11;
const int inf = 0x3f3f3f3f;
using namespace std;
struct trie {
    trie* nxt[28];
    int cnt;
    trie()
    {
        cnt = 1;
        memset(nxt, 0, sizeof(nxt));
    }
};

trie* root;
int n;
string S, s;
vector<string> v;

void Insert(string s)
{
    trie* p = root;
    for (int i = 0; i < s.length(); i++) {
        int id = s[i] - 'a';
        if (s[i] == '/')
            id = 26;
        else if (s[i] == '.')
            id = 27;
        if (p->nxt[id]) {
            p = p->nxt[id];
            p->cnt++;
        }
        else {
            p->nxt[id] = new trie;
            p = p->nxt[id];
        }
    }
}

int query(string s)
{
    trie* p = root;
    for (int i = 0; i < s.length(); i++) {
        int id = s[i] - 'a';
        if (s[i] == '/')
            id = 26;
        else if (s[i] == '.')
            id = 27;
        if (p->nxt[id])
            p = p->nxt[id];
        else
            return 0;
    }
    return p->cnt;
}

void Free(trie* p)
{
    for (int i = 0; i < 28; ++i)
        if (p->nxt[i] != NULL)
            Free(p->nxt[i]);
    delete (p);
    p = NULL;
}

int main()
{
    root = new trie();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int l = s.length();
        if (s[l - 1] == 'j' && s[l - 2] == 'o' && s[l - 3] == 'e' && s[l - 4] == '.')
            v.push_back(s);
        Insert(s);
    }
    int ans = 0;
    for (auto& x : v) {
        if (query(x) < 2)
            ans++;
    }
    cout << ans << endl;
    return 0;
}