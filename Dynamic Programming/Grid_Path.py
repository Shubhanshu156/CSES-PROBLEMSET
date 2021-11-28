n=int(input())
mod=1000000007
lst=[]
dp=[]
for i in range(n):
    lst2=list(input())
    lst.append(lst2)
    dp.append([0]*(n))
# print(lst)
dp[0][0]=1
for i in range(n):
    for j in range(n):
        if lst[i][j]=='*':
            dp[i][j]=0
            continue
        if i>0:
            dp[i][j]+=dp[i-1][j]
        if j>0:
            dp[i][j]+=dp[i][j-1]

print(dp[-1][-1]%mod)