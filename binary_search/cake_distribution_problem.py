# User function Template for python3


class Solution:
    def ok(self, s, n, k, val):
        curr = 0
        for i in range(n):
            curr += s[i]
            if curr >= val:
                k -= 1
                curr = 0

        return k < 0

    def maxSweetness(self, sweetness, n, k):
        # your code goes here
        lo, hi = 1, 10**14
        ans = 0
        while lo <= hi:
            mid = (lo + hi) // 2
            if self.ok(sweetness, n, k, mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

for _ in range(int(input())):
    n, k = map(int, input().split())
    sweetness = [int(i) for i in input().split()]
    print(Solution().maxSweetness(sweetness, n, k))
# } Driver Code Ends
