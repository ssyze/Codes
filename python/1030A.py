'''
@Date         : 2019-12-21 22:21:02
@Author       : ssyze
@Description  : 
'''
n = int(input())
flag = 0
lst = list(map(int, input().split()))
for i in lst:
    if i == 1:
        flag = 1
if flag == 1:
    print("HARD")
else:
    print("EASY")
