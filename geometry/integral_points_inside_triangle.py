# User function Template for python3
import math


class Solution:
    def area(self, p, q, r):
        return (
            abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1])) // 2
        )

    def InternalCount(self, p, q, r):
        # code here
        b = math.gcd(abs(p[0] - q[0]), abs(p[1] - q[1]))
        b += math.gcd(abs(p[0] - r[0]), abs(p[1] - r[1]))
        b += math.gcd(abs(r[0] - q[0]), abs(r[1] - q[1]))
        return self.area(p, q, r) + 1 - b // 2


# {
# Driver Code Starts
# Initial Template for Python 3

import math

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        p = [0] * 2
        q = [0] * 2
        r = [0] * 2
        p[0], p[1], q[0], q[1], r[0], r[1] = map(int, input().strip().split(" "))
        ob = Solution()
        ans = ob.InternalCount(p, q, r)
        print(ans)
# } Driver Code Ends
