class Solution:
    def remainingMethods(self, n: int, k: int, inv: List[List[int]]) -> List[int] :
        indegree = [0] * n
        sus = [False] * n 
        adj = [[] for _ in range(n)]
        for i in inv :
            adj[i[0]].append(i[1])
            indegree[i[1]] += 1

        def dfs(i):
            sus[i] = True 
            for v in adj[i]:
                indegree[v] -= 1
                if not sus[v]:
                    dfs(v)
        dfs(k)
        for i in range(n):
            if indegree[i]  and sus[i] == True :
                a = [0] * n
                for j in range(n) :
                    a[j] = j
                return a
        ans = []
        for i in range(n):
            if not sus[i] :
                ans.append(i)
        return ans