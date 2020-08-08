/*
 * @Date         : 2020-07-28 13:10:19
 * @Author       : ssyze
 * @Description  : 
 */ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+100;

int t,n,len,nxt[maxn],pre,cur;
char s[maxn];

int main(){
    scanf("%d",&t);
    while(t--){
        cur = pre = 0;
        memset(nxt,0,sizeof(nxt));
        scanf("%s",s+1);
        len = strlen(s+1);
        int tmp = 0;
        for (int i = 1; i <= len; ++i) {
            if(s[i] == '(') tmp++;
            else if(s[i] == ')'){
                tmp--;
                if (tmp < 0) {
                    if (nxt[cur] == 0) break;
                    cur = nxt[cur];
                    s[cur] = '(';
                    tmp = 0;
                }
            }
            else{
                nxt[pre] = i;
                pre = i;
            }
        }
        if (tmp > 0) {
            for(int i = len; i >= 1 && tmp != 0; --i){
                if (s[i] == '*') s[i] = ')',tmp--; 
            }
        }
        tmp = 0;
        for(int i = 1; i <= len; ++i){
            if(s[i] == '(') tmp++;
            else if(s[i] == ')'){
                tmp--;
                if(tmp < 0) break;
            }
        }
        if(tmp != 0) puts("No solution!");
        else{
            for(int i = 1; i <= len; ++i){
                if(s[i] != '*') putchar(s[i]);
            }
            puts("");
        }
            
        
    }
}