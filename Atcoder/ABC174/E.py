'''
Date         : 2020-08-09 00:46:52
Author       : ssyze
Description  : 
'''
n, k = map(int, input().split())
a = list(map(int, input().split()))


def check(m):
    sum = 0
    for i in range(len(a)):
        sum += (a[i] - 1) // m
    if sum > k:
        return False
    else:
        return True


l = 1
r = 10**9
ans = 10**9
while l < r:
    mid = (l + r) // 2
    if check(mid) == 1:
        r = mid
        ans = mid
    else:
        l = mid + 1
print(ans)
