class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[0] * (n+1) for _ in range(n+1)]
        def rec(i , j):
            if i == j:
                return piles[i]
            if dp[i][j] != -1 :
                return dp[i][j]
            dp[i][j] =  max(
                piles[i] - rec(i+1 , j) , piles[j] - rec(i , j-1)
            )
            return dp[i][j]
        for i in range(n-1 , -1 , - 1):
            for j in range(n):
                dp[i][j] = max(piles[i] - dp[i+1][j] , piles[j] - dp[i][j+1])
        
        # return rec(0 ,n-1) > 0 
        return dp[0][n-1] > 0

