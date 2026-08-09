class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        # n = len(piles)
        # sm = sum(piles)
        # prefix = [0]* (n+1)
        # for i in range(n):
        #     prefix[i+1] = prefix[i] + piles[i]
        # dp = [[0] for _ in range(n)]
        # def rec( i , m ):
        #     if i >= n:
        #         return 0 
        #     maxi = -1e10 
        #     left = sm - prefix[i]
        #     for j in range(1 , 2*m + 1):
        #         if i + j > n :
        #             break
        #         maxi = max(maxi , left - rec(i+j , max(j , m)))
        #     return maxi

        n = len(piles)

        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + piles[i]

        dp = [[0] * (n + 1) for _ in range(n + 1)]

        # Fill from the back
        for i in range(n - 1, -1, -1):
            for m in range(1, n + 1):

                total = prefix[n] - prefix[i]

                for x in range(1, min(2 * m, n - i) + 1):

                    opponent = dp[i + x][max(m, x)]

                    curr = total - opponent

                    dp[i][m] = max(dp[i][m], curr)

        return dp[0][1]

