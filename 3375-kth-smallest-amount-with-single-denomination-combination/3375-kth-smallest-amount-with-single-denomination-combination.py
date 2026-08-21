class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        n = len(coins)
        coins.sort()
        l , h = 1 , k * coins[n-1]
        res = -1
        def solve(m) : 
            order = 0 
            for i in range((1 << n)):
                cnt ,lcm= 0 , 0 
                for j in range(n) :
                    if (i & (1 << j) ) > 0 :
                        cnt += 1
                        if lcm == 0 : lcm = coins[j]
                        else : lcm = lcm * coins[j] // gcd(lcm , coins[j])
                if cnt%2 == 0 and lcm != 0:
                    order -= m // lcm 
                elif cnt%2 == 1 and lcm != 0 : order += m // lcm 
            return order 
        while  l <= h :
            m = l + (h - l) // 2
            if solve(m) >= k :
                res = m 
                h = m - 1
            else : l = m + 1

        
        return res

