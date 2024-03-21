# User function template for Python


class Solution:
    def rectanglesInCircle(self, R):
        # code here
        ans = 0
        d = (R + R) ** 2
        for i in range(1, R + R):
            for j in range(1, R + R):
                if i * i + j * j <= d:
                    ans += 1
                else:
                    break
        return ans


# {
# Driver Code Starts
# Initial Template for Python

import math

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ans = ob.rectanglesInCircle(N)
        print(ans)
# } Driver Code Ends
