
n=int(input())
dp=[0]*(n+1)
mod=(10**9)+7
dp[0]=1
dp[1]=1
# caculate 
for i in range(2,n+1):
    for j in range(1,7):
        if i-j>=0:
            dp[i]=(dp[i]%mod)+(dp[i-j]%mod)%mod
print(dp[n]%mod)


