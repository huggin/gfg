# User function Template for python3
class Solution:
    def firstElement(self, n):
        # code here
        m = 1000000007
        a = 0
        b = 1
        for _ in range(n):
            a, b = b, (a+b) % m

        return a


# {
 # Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        print(ob.firstElement(n))
# } Driver Code Ends
