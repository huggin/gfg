# User function Template for python3
class Solution:
    def maxArea(self, mat, r, c):
        # code here
        hist = [[0 for _ in range(c)] for _ in range(r)]
        for j in range(c):
            hist[0][j] = mat[0][j]

        for i in range(1, r):
            for j in range(c):
                if mat[i][j]:
                    hist[i][j] = hist[i - 1][j] + mat[i][j]

        for i in range(r):
            hist[i].sort(reverse=True)

        ans = 0
        for i in range(r):
            for j in range(c):
                ans = max(ans, hist[i][j] * (j + 1))
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        r, c = list(map(int, input().strip().split()))
        inputLine = list(map(int, input().strip().split()))
        mat = [[False for j in range(c)] for i in range(r)]
        k = 0
        for i in range(r):
            for j in range(c):
                mat[i][j] = inputLine[k]
                k += 1
        ob = Solution()
        ans = ob.maxArea(mat, r, c)
        print(ans)
        tc -= 1

# } Driver Code Ends
