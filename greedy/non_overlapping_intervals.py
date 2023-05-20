# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def minRemoval(self, N, intervals):
        # Code here
        intervals.sort(key=lambda x: (x[1], x[0]))
        prev = intervals[0]
        ans = 0
        for i in range(1, N):
            if prev[1] <= intervals[i][0]:
                prev = intervals[i]
            else:
                ans += 1

        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        intervals = [list(map(int, input().split())) for i in range(N)]
        ob = Solution()
        res = ob.minRemoval(N, intervals)
        print(res)
# } Driver Code Ends
