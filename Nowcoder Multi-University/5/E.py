'''
@Date         : 2020-07-25 13:34:50
@Author       : ssyze
@Description  : 
'''
n = int(input())
a = list(map(lambda x: int(x)-1, input().split()))
vis = [0]*n
arr = []
sol = [0]*(n+1)
ans = 1


def getlen(u):
    leng = 1
    vis[u] = 1
    while vis[a[u]] == 0:
        leng = leng+1
        u = a[u]
        vis[u] = 1
    arr.append(leng)


for i in range(n):
    if(vis[i] == 0):
        getlen(i)

arr.sort(reverse=1)

for i in range(len(arr)):
    x = arr[i]
    if(sol[x] == 1):
        continue
    sol[x] = 1
    ans = ans*x
    for j in range(i+1, len(arr)):
        if x % arr[j] == 0:
            sol[arr[j]] = 1

print(ans)
