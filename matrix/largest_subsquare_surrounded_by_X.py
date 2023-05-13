# User function Template for python3


class Solution:
    def largestSubsquare(self, N, A):
        # code here
        m = [[[0 for _ in range(N)] for _ in range(N)] for _ in range(2)]
        for i in range(N):
            m[0][i][0] = 1 if A[i][0] == "X" else 0
            for j in range(1, N):
                if A[i][j] == "X":
                    m[0][i][j] = m[0][i][j - 1] + 1

        for j in range(N):
            m[1][0][j] = 1 if A[0][j] == "X" else 0
            for i in range(1, N):
                if A[i][j] == "X":
                    m[1][i][j] = m[1][i - 1][j] + 1

        ans = 0
        for i in range(N):
            for j in range(N):
                d = min(m[0][i][j], m[1][i][j])
                while d > 0:
                    if m[0][i - d + 1][j] >= d and m[1][i][j - d + 1] >= d:
                        ans = max(d, ans)
                        break
                    d -= 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

import math

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        a = []
        for i in range(N):
            s = list(map(str, input().strip().split()))
            a.append(s)
        ob = Solution()
        print(ob.largestSubsquare(N, a))
# } Driver Code Ends
