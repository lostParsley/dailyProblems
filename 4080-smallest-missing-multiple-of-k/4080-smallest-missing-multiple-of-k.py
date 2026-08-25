class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        for i in range(1,1000):
            if i * k not in nums : return i * k
        return 0