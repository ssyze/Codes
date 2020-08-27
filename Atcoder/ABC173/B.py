'''
Date         : 2020-08-10 14:56:09
Author       : ssyze
Description  : 
'''
n = int(input())
ac = 0
tle = 0
wa = 0
re = 0
for i in range(n):
    s = input()
    if s == 'AC':
        ac += 1
    elif s == 'TLE':
        tle += 1
    elif s == 'WA':
        wa += 1
    else:
        re += 1
print("AC x %d" % ac)
print("WA x %d" % wa)
print("TLE x %d" % tle)
print("RE x %d" % re)
