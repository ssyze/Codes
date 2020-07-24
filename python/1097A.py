'''
@Date         : 2019-12-21 22:50:32
@Author       : ssyze
@Description  : 
'''
a = input()
lst = list(input().split())
f = 0
for i in lst:
    if i[0] == a[0] or i[1] == a[1]:
        f = 1
if f == 1:
    print("YES")
else:
    print("NO")
