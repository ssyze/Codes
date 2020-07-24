#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 210;
int t,n,ans,Case;
char s1[maxn],s2[maxn],s3[maxn],s12[maxn];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        scanf("%s",s1);scanf("%s",s2);scanf("%s",s12);
        int tmp = 0,ans = 0,flag = 0;
        for(int i=0;i<n;i++)
        {
            s3[tmp++]=s2[i];
            s3[tmp++]=s1[i];
        }
        s3[tmp] = '\0';
        while(strcmp(s3,s12))
        {
            if(ans > 1000)
            {
                flag = 1;
                break;
            }
            int tmp = 0,i;
            for(i=0;i<n;i++)
                s1[i] = s3[tmp++];
            s1[i] = '\0';
            for(i=0;i<n;i++)
                s2[i] = s3[tmp++];
            s2[i] = '\0';
            ans++;tmp = 0;
            for(i=0;i<n;i++)
            {
                s3[tmp++] = s2[i];
                s3[tmp++] = s1[i];
            }
            s3[tmp] = '\0';
        }
        if(flag)
            printf("%d -1\n",++Case);
        else
            printf("%d %d\n",++Case, ans?ans+1:ans);
    }
}