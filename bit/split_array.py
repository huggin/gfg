# User function Template for python3
class Solution:
    def countgroup(self, a, n):
        # Complete the function
        xor = 0
        for i in a:
            xor ^= i
        if xor != 0:
            return 0

        return pow(2, n - 1, 1000000007) - 1


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    ob = Solution()
    print(ob.countgroup(arr, n))


# } Driver Code Ends
