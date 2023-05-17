# User function Template for python3


class Solution:
    def dyckPaths(self, N):
        # code here
        ans = 1
        for i in range(1, N + 1):
            ans *= N + i
            ans //= i

        return ans // (N + 1)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        print(ob.dyckPaths(N))
# } Driver Code Ends
