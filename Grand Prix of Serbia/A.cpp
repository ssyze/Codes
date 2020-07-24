/*
 * @Date         : 2020-05-17 17:41:58
 * @Author       : ssyze
 * @Description  : 
 */ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000;
int n,k,x,a[maxn],st,ed,spe,fix;
vector<int> need;
int main()
{
    cin >> n >> k >> x;
    a[1] = 1;
    for(int i = n-1,j = 2; i >= 0; --i,++j){
        if(k >= i){
            k-= i;
            a[j] = a[j-1]+x;
        }
        else{
            fix = 1;
            st = j-1;ed = n-k+1;
            spe=a[j-1]+x;
            break;
        }
    }
    if(fix){
        for(int j = st+1; j < ed; ++j) a[j]=a[st]+1;
        a[ed]=spe;
        for(int j = ed+1; j <= n; ++j) a[j]=spe;
    }
    for(int i = 1; i <= n; ++i) cout << a[i] << " ";
}