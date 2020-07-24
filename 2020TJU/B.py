'''
@Date         : 2020-05-10 13:43:02
@Author       : ssyze
@Description  : 
'''
s = input().split('+')
sum = 0
for i in s:
    tmp = list(map(int, i.split('d')))
    if len(tmp) > 1:
        sum = sum + tmp[0] * (tmp[1] + 1) / 2
    else:
        sum = sum + tmp[0]
s = str(sum).split('.')
flag = 1
if (len(s) > 1):
    if (float(s[1]) != 0):
        flag = 0
if flag:
    print("%d" % sum)
else:
    print("%.1f" % sum)
