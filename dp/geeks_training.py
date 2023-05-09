# User function Template for python3


class Solution:
    def maximumPoints(self, points, n):
        # Code here
        dp = points[0].copy()
        dp2 = [0] * 3
        for i in range(1, n):
            for j in range(3):
                dp2[j] = max(dp[(j + 1) % 3], dp[(j + 2) % 3]) + points[i][j]
            dp = dp2.copy()

        return max(dp)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        points = [list(map(int, input().split())) for _ in range(n)]
        ob = Solution()
        print(ob.maximumPoints(points, n))
# } Driver Code Ends
