/*
 * @Date         : 2020-07-28 12:18:01
 * @Author       : ssyze
 * @Description  : 
 */ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+100;


int t,n,p;
set<ll> vis;
ll a[maxn],sum[maxn],ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> p;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            sum[i] = a[i];
            sum[i] += sum[i-1];
            ll res = sum[i] % p;
            if(res == 0 || vis.count(res)){
                ans ++;
                vis.clear();
            }
            else vis.insert(res);
        }
        cout << ans << endl;
    }

}