class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        ans = []
        n = len(s)
        sz = 1e10
        for i in range(n):
            st = ""
            cnt = 0
            for j in range(i , n):
                st += s[j]
                if s[j] == '1' : cnt += 1
                if cnt == k :
                    ans.append(st)
                    sz = min(sz , j - i + 1)
                    break
        ans = [i for i in ans if len(i) <= sz ]
        ans.sort()
        if len(ans) == 0 : return ''
        return ans[0]