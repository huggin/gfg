# User function Template for python3
from functools import lru_cache


class Solution:
    def match(self, wild, pattern):
        # code here
        n = len(wild)
        m = len(pattern)

        @lru_cache(maxsize=None)
        def f(i, j):
            if j == m:
                for k in range(i, n):
                    if wild[k] != "*":
                        return False
                return True

            if i == n and i < m:
                return False

            if wild[i] == pattern[j] or wild[i] == "?":
                return f(i + 1, j + 1)

            if wild[i] == "*":
                ans = False
                for k in range(j, m):
                    ans = ans or f(i + 1, k + 1)
                return ans

            return False

        return f(0, 0)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        wild = input()
        pattern = input()

        ob = Solution()
        if ob.match(wild, pattern):
            print("Yes")
        else:
            print("No")
# } Driver Code Ends
