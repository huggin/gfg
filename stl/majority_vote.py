# User function Template for python3
from collections import Counter


class Solution:
    def Solve(self, n, a):
        # Code here
        c = Counter(a)
        ans = []
        for k, v in c.items():
            if v > n // 3:
                ans.append(k)

        return ans if len(ans) > 0 else [-1]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        ob = Solution()
        res = ob.Solve(n, a)
        for val in res:
            print(val, end=" ")
        print()
# } Driver Code Ends
