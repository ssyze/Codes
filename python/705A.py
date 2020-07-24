'''
@Date         : 2019-12-21 22:32:13
@Author       : ssyze
@Description  : 
'''
n = int(input())
ans = 0
while ans != n-1:
    ans = ans + 1
    if ans % 2 == 1:
        print("I hate that ", end='')
    else:
        print("I love that ", end='')
ans = ans + 1
if ans % 2 == 1:
    print("I hate it")
else:
    print("I love it")
