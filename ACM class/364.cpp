#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
string s[maxn];
int n;
bool cmp(string a,string b)
{
    return (a+b) > (b+a);
}
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>s[i];
        sort(s+1,s+n+1,cmp);
        for(int i=1;i<=n;i++)
            cout<<s[i];
        cout<<endl;
    }
}