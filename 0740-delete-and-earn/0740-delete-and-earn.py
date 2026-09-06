class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        sm = [0] * (nums[-1] + 2)

        for x in nums:
            sm[x] += x
        dp = [0]* (nums[-1] + 2)
        dp[nums[-1]] = sm[nums[-1]]
        for i in range(nums[-1]-1, -1 ,-1):
            skip = dp[i+1]
            take = dp[i+2] + sm[i]
            dp[i] = max(skip , take)
        return dp[0]
