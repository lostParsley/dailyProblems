class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        n = len(nums)
        ans = [0] * 2
        for i in range(n) : 
            curr = nums[i] 
            to_find = target - curr 
            for j in range(i+1 , n):  
                if nums[j] == to_find :
                    ans[0] = i 
                    ans[1] = j
        return ans


