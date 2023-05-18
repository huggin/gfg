# User function Template for python3
from collections import defaultdict


class Solution:
    def countSubarray(self, n, nums, k):
        # Code here
        m = defaultdict(int)
        m[0] = 1
        ans = 0
        curr = 0
        for i in range(n):
            if nums[i] % 2 == 1:
                curr += 1
            m[curr] += 1
            ans += m[curr - k]
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        nums = list(map(int, input().split()))
        k = int(input())
        ob = Solution()
        print(ob.countSubarray(n, nums, k))
# } Driver Code Ends
