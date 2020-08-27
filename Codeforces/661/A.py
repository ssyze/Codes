'''
Date         : 2020-08-10 23:37:57
Author       : ssyze
Description  : 
'''
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    flag = 0
    for i in range(n - 1):
        if a[i + 1] - a[i] >= 2:
            print("NO")
            flag = 1
            break
    if flag == 0:
        print("YES")
