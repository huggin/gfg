# User function Template for python3


class Solution:
    def CountPairs(self, arr, n):
        # code here.
        n = sum(1 for a in arr if a > 1)
        two = arr.count(2)

        return n * (n - 1) // 2 - two * (two - 1) // 2


# {
# Driver Code Starts
# Initial Template for Python 3


t = int(input())
for _ in range(0, t):
    n = int(input())
    a = list(map(int, input().split()))
    ob = Solution()
    print(ob.CountPairs(a, n))


# } Driver Code Ends
