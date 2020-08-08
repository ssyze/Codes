'''
Date         : 2020-08-08 22:19:33
Author       : ssyze
Description  : 
'''
from math import *
n, d = map(int, input().split())
n = int(n)
ans = 0
for i in range(n):
    x, y = map(int, input().split())
    if x * x + y * y <= d * d:
        ans += 1
print(ans)
