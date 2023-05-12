# User function Template for python3


class Solution:
    def findNth(self, N):
        # code here
        a = []
        while N:
            a.append(N % 9)
            N //= 9

        ans = 0
        for i in range(len(a) - 1, -1, -1):
            ans = ans * 10 + a[i]
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

t = int(input())
for i in range(0, t):
    n = int(input())
    obj = Solution()
    s = obj.findNth(n)
    print(s)
# } Driver Code Ends
