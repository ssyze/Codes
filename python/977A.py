'''
@Date         : 2019-12-21 22:10:21
@Author       : ssyze
@Description  : python practise
'''
n, k = input().split()
n = int(n)
k = int(k)
a = 0
while a != k:
    if n % 10 == 0:
        n = n // 10
        a = a + 1
    else:
        n = n - 1
        a = a + 1
print(n)
