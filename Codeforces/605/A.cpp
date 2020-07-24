#include <bits/stdc++.h>
using namespace std;
int a[3];
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        cout<<max(0,2*(a[2]-a[0]-2))<<endl;
    }
}