# User function Template for python3
from collections import defaultdict


class Solution:
    def longLenSub(self, arr, n):
        # Complete the function
        d = defaultdict(int)
        ans = 0
        for a in arr:
            d[a] = max(d[a - 1], d[a + 1]) + 1
            ans = max(ans, d[a])
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    ob = Solution()
    v = ob.longLenSub(arr, n)
    print(v)

# } Driver Code Ends
