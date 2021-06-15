n = int(input())
dp=[[],[]]
ans=[0,10]
for i in range(10):
    dp[-1].append(1)
    
for i in range(2,1001):
    dp.append([ans[-1]])
    ans.append(dp[-1][0])
    for j in range(1,10):
        dp[i].append(dp[i][j-1]-dp[i-1][j-1])
        ans[i]+=dp[i][j]

print(ans[n]%10007)