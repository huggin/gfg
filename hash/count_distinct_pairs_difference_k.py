# User function Template for python3
from collections import defaultdict


class Solution:
    def TotalPairs(self, nums, k):
        # Code here
        nums.sort()
        d = set()
        ans = 0
        if k == 0:
            for i in range(1, n):
                if nums[i] == nums[i - 1] and nums[i] not in d:
                    ans += 1
                    d.add(nums[i])
        else:
            for a in nums:
                if a in d:
                    continue
                if a - k in d:
                    ans += 1
                d.add(a)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, k = input().split()
        n = int(n)
        k = int(k)
        nums = list(map(int, input().split()))
        ob = Solution()
        ans = ob.TotalPairs(nums, k)
        print(ans)
# } Driver Code Ends
