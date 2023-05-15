# User function Template for python3
class Solution:
    def ok(self, nums, k, mi):
        return sum((a + mi - 1) // mi for a in nums) <= k

    def smallestDivisor(self, nums, K):
        # Code here
        lo, hi = 1, max(nums)
        ans = 0
        while lo <= hi:
            mi = (lo + hi) // 2
            if self.ok(nums, K, mi):
                ans = mi
                hi = mi - 1
            else:
                lo = mi + 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, K = list(map(int, input().split()))
        nums = list(map(int, input().split()))
        ob = Solution()
        res = ob.smallestDivisor(nums, K)
        print(res)
# } Driver Code Ends
