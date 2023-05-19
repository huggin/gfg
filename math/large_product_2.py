# User function Template for python3
import math


class Solution:
    def Find(self, nums):
        # Code here
        total = 0
        n = len(nums)
        for a in nums:
            total += math.log(a)
        total /= n

        x = math.exp(total)
        return math.ceil(x)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        nums = list(map(int, input().split()))
        ob = Solution()
        ans = ob.Find(nums)
        print(ans)

# } Driver Code Ends
