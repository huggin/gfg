# User function Template for python3


class Solution:
    def findLargest(self, N, S):
        # code here
        if S > N * 9 or S == 0 and N != 1:
            return -1
        ans = 0
        for i in range(N):
            d = min(S, 9)
            S -= d
            ans = ans * 10 + d
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, S = [int(x) for x in input().split()]

        ob = Solution()
        print(ob.findLargest(N, S))
# } Driver Code Ends
