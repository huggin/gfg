# User function Template for python3

class Solution:
    def colName(self, n):
        # your code here
        ans = []
        while n:
            n -= 1
            ans.append(chr(n % 26 + ord('A')))
            n //= 26

        return ''.join(reversed(ans))

# {
 # Driver Code Starts
# Initial Template for Python 3


t = int(input())
for tc in range(t):
    n = int(input())
    ob = Solution()
    print(ob.colName(n))


# } Driver Code Ends
