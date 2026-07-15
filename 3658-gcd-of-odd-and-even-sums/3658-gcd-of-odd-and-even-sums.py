class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        od , ev = 0 , 0
        for i in range(1 , 2*n+1) :
            if i%2 == 0 :
                ev += i 
            else : od += i
        return gcd(od , ev)