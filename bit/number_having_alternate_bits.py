# User function Template for python3
class Solution:
    def bitsAreInAltOrder(self, n):
        # code here
        s = bin(n)
        for i in range(3, len(s)):
            if s[i] == s[i - 1]:
                return 0
        return 1


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        print(ob.bitsAreInAltOrder(n))
# } Driver Code Ends
