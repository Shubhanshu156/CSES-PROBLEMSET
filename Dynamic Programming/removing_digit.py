n=int(input())
dp=[float('inf')]*(n+1)
if n<=9:
    print(1)
else:

    dp[0]=1;dp[1]=1;dp[2]=1;dp[3]=1;dp[4]=1;dp[5]=1;dp[6]=1;dp[7]=1;dp[8]=1;dp[9]=1

    for i in range(10,n+1):
        num=i
        while(i>0):
            d=i%10
            i=i//10
            dp[num]=min(dp[num],dp[num-d]+1)
    print(dp[n])
