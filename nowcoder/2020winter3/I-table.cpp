/*
 * @Date         : 2020-02-08 15:48:54
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, step;
map<pair<char, char>, int> mp;
void Han(int n, char a, char b, char c)
{
    if (n == 1) {
        mp[{ a, c }]++;
        step++;
    }
    else {
        Han(n - 1, a, c, b);
        mp[{ a, c }]++;
        step++;
        Han(n - 1, b, a, c);
    }
}
int main()
{
    for (n = 1; n <= 32; n++) {
        mp[{ 'a', 'c' }] = 0;
        mp[{ 'a', 'b' }] = 0;
        mp[{ 'b', 'c' }] = 0;
        mp[{ 'b', 'a' }] = 0;
        mp[{ 'c', 'a' }] = 0;
        mp[{ 'c', 'b' }] = 0;
        step = 0;
        Han(n, 'a', 'b', 'c');
        /* printf("A->B:%d\n", mp[{ 'a', 'b' }]);
        printf("A->C:%d\n", mp[{ 'a', 'c' }]);
        printf("B->A:%d\n", mp[{ 'b', 'a' }]);
        printf("B->C:%d\n", mp[{ 'b', 'c' }]);
        printf("C->A:%d\n", mp[{ 'c', 'a' }]);
        printf("C->B:%d\n", mp[{ 'c', 'b' }]);
        printf("SUM:%d\n\n", step); */
        cout << mp[{ 'a', 'b' }] << ' ' << mp[{ 'a', 'c' }] << ' ' << mp[{ 'b', 'a' }] << ' ' << mp[{ 'b', 'c' }] << ' ' << mp[{ 'c', 'a' }] << ' ' << mp[{ 'c', 'b' }] << ' ' << step << endl;
    }
}