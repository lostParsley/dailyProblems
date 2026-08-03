class Solution:
    def stoneGameIII(self, s: List[int]) -> str:
        n = len(s)
        dp = [[-1]*2 for _ in range(n)]
        def rec(i,j,f):
            if i > j :
                return 0
            if dp[i][f] != -1 : return dp[i][f]
            if f == 0:
                a = s[i] - rec(i+1 , j ,1)
                b , c = -1e10 , -1e10 
                if i + 1 < n :  
                    b = s[i] + s[i+1] - rec(i+2 , j , 1)
                if i+2 < n :
                    c = s[i] + s[i+1] + s[i+2] - rec(i+3 , j , 1)
                dp[i][f] =  max(a , b, c)
                return dp[i][f]
            if f ==1 :
                a = s[i] - rec(i+1 , j ,0)
                b , c = -1e10 , -1e10 
                if i + 1 < n :  
                    b = s[i] + s[i+1] - rec(i+2 , j , 0)
                if i+2 < n :
                    c = s[i] + s[i+1] + s[i+2] - rec(i+3 , j , 0)
                dp[i][f] =  max(a , b, c)
                return dp[i][f]
        # return 'Alice' if rec(0 , n-1 , 0) > 0  else  'Bob'
        a = rec(0 , n-1 , 0)
        if a > 0 : return 'Alice'
        elif a < 0 : return 'Bob'
        else : return 'Tie'