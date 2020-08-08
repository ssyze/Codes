'''
@Date         : 2020-08-01 12:07:11
@Author       : ssyze
@Description  : 
'''
from math import *
t = int(input())
for ti in range(t):
    for n in range(1, 1000000000):
        sum = n * (n + 1) * (2 * n + 1) / 6
        sq = int(sqrt(sum))
        if sq * sq == sum:
            print("Fake news!")
            print(n)
