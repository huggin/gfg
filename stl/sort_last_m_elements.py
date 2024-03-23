# User function Template for python3


class Solution:
    def sortLastMelements(self, nums, n, m):
        # Code here
        nums[n:] = sorted(nums[n:])


# {
# Driver Code Starts

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, m = map(int, input().strip().split())
        nums = list(map(int, input().strip().split()))
        obj = Solution()
        obj.sortLastMelements(nums, n, m)
        for i in nums:
            print(i, end=" ")
        print()
# } Driver Code Ends
