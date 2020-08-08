'''
Date         : 2020-08-08 12:09:28
Author       : ssyze
Description  : 
'''
s = input()
l = list()

for i in range(len(s)):
    if s[i] == ')':
        num = 0
        while l[-1] != -1:
            num = int(num) + int(l[-1])
            l.pop()
        l.pop()
        l.pop()
        l.append(2**num)
    else:
        if s[i] == '(':
            l.append(-1)
        elif s[i] != '+':
            l.append(int(s[i]))

ans = 0
for i in range(len(l)):
    ans += int(l[i])
print(ans)
