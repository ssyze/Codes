#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        int l=0,r=0,u=0,d=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='L')   l++;
            if(s[i]=='R')   r++;
            if(s[i]=='U')   u++;
            if(s[i]=='D')   d++;
        }
        l = min(l,r);   r = l;
        u = min(u,d);   d = u;
        if(l==0)
        {
            if(u==0)
                cout<<"0\n\n";
            else
                cout<<"2\nUD\n";
        }
        else if(u==0)
        {
            if(l==0)
                cout<<"0\n\n";
            else
                cout<<"2\nLR\n";
        }
        else
        {
            cout<<2*l+2*u<<endl;
            for(int i=0;i<l;i++)
                cout<<'L';
            for(int i=0;i<u;i++)
                cout<<'U';
            for(int i=0;i<r;i++)
                cout<<'R';
            for(int i=0;i<d;i++)
                cout<<'D';
            cout<<endl;
        }
    }
}