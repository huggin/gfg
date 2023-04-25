# User function Template for python3


class Solution:
    def onlyFirstAndLastAreSet(self, n):
        # code here
        if (n & 1) == 0:
            return 0
        if ((n - 1) & (n - 2)) == 0:
            return 1
        return 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        S = int(input())
        ob = Solution()
        ans = ob.onlyFirstAndLastAreSet(S)
        print(ans)
# } Driver Code Ends
