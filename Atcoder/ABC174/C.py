'''
Date         : 2020-08-08 23:01:16
Author       : ssyze
Description  : 
'''
from math import *
k = int(input())
x = 7
cnt = 1
while x % k != 0:
    x = (x * 10 + 7) % k
    cnt += 1
    if cnt >= 10**6 + 5:
        break
if cnt >= 10**6 + 5:
    print("-1")
else:
    print(cnt)
