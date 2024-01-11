# User function Template for python3


class Solution:
    def getLastDigit(self, a, b):
        # code here
        d = int(a[-1])
        ans = 1
        n = len(b)
        for i in range(n - 1, -1, -1):
            ans = (ans * d ** int(b[i])) % 10
            d = d**10 % 10
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a, b = map(str, input().split())

        ob = Solution()
        print(ob.getLastDigit(a, b))
# } Driver Code Ends
