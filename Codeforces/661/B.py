'''
Date         : 2020-08-10 23:46:55
Author       : ssyze
Description  : 
'''
from math import *
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    mna = min(a)
    mnb = min(b)
    ans = 0
    for i in range(n):
        ans += max(a[i] - mna, b[i] - mnb)
    print(ans)
