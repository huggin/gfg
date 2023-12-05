# User function Template for python3


class Solution:
    def countX(self, L, R, X):
        # code here
        def f(a):
            ans = 0
            while a > 0:
                if a % 10 == X:
                    ans += 1
                a //= 10
            return ans

        ans = 0
        for i in range(L + 1, R):
            ans += f(i)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

import math

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        L, R, X = map(int, input().strip().split(" "))
        ob = Solution()
        ans = ob.countX(L, R, X)
        print(ans)
# } Driver Code Ends
