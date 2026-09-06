class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n = len(s)

        # def rec(i,tmp): 
        #     if tmp == len(t) :
        #         return 1
        #     if i == n : return 0 
        #     skip =  rec(i+1 , tmp)
        #     take = rec(i+1, tmp+1) if tmp < len(t) and s[i] == t[tmp] else 0
        #     return skip + take
        # return rec(0 , 0)
        dp = [[0 for _ in range(len(t)+1)] for _ in range(n+1)]
        for i in range(n+1):
            dp[i][len(t)] = 1
        for i in range(n-1 , -1 , - 1):
            for j in range(len(t)-1  , -1 , -1) : 
                skip = dp[i+1][j]
                take = dp[i+1][j+1] if s[i] == t[j] else 0 
                dp[i][j] = skip + take 
        return dp[0][0]