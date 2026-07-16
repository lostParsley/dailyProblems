class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        mx = nums[0]
        n = len(nums)
        gd = [0] * n 
        gd[0] = nums[0]

        for i in range(1 , n):
            mx = max(mx , nums[i])
            gd[i] = gcd(nums[i] , mx)
        gd.sort()

        sm = 0
        for i in range(n//2):
            sm += gcd(gd[i] , gd[n-i-1])
        return sm
