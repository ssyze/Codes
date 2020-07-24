#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int can[27];
string s;
signed main()
{
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<k;i++)
    {
        char a;
        cin>>a;
        can[a-'a']=1;
    }
    int len = 0,ans = 0;
    for(int i=0;i<s.length();i++)
    {
        if(can[s[i]-'a'])
            len++;
        else
        {
            ans += len*(len-1)/2;
            ans += len;
            len = 0;
        }
    }
    ans += len; ans += len*(len-1)/2;
    cout<<ans<<endl;
}