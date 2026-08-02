class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[-1] * n for _ in range(n)]
        def rec(i , j):
            if i == j:
                return piles[i]
            if dp[i][j] != -1 :
                return dp[i][j]
            dp[i][j] =  max(
                piles[i] - rec(i+1 , j) , piles[j] - rec(i , j-1)
            )
            return dp[i][j]
        return rec(0 ,n-1) > 0 

