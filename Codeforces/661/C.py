'''
Date         : 2020-08-10 23:56:24
Author       : ssyze
Description  : 
'''
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    dic = dict()
    for i in range(n - 1):
        for j in range(i + 1, n):
            if dic.__contains__(a[i]+a[j]):
                dic[a[i]+a[j]] += 1
            else:
                dic[a[i]+a[j]] = 1
    print(dic)
