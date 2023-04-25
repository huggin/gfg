# User function Template for python3


class Solution:
    def nearestPowerOf2(self, N):
        # code here
        p = 1
        while N > p:
            p *= 2
        return p


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        print(ob.nearestPowerOf2(N))
# } Driver Code Ends
