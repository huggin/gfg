# User function Template for python3
class Solution:
    def costOfSweets(self, M):
        # code here
        return M - ((M + 2) // 4 * 2)


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        M = int(input())

        ob = Solution()
        print(ob.costOfSweets(M))
# } Driver Code Ends
