# User function Template for python3


class Solution:
    def Maximum_Sum(self, mat, N, K):
        # Your code goes here
        prefix = [[0 for _ in range(N)] for _ in range(N)]
        prefix[0][0] = mat[0][0]
        for i in range(1, N):
            prefix[0][i] = prefix[0][i - 1] + mat[0][i]
            prefix[i][0] = prefix[i - 1][0] + mat[i][0]

        for i in range(1, N):
            for j in range(1, N):
                prefix[i][j] = (
                    mat[i][j]
                    + prefix[i - 1][j]
                    + prefix[i][j - 1]
                    - prefix[i - 1][j - 1]
                )

        ans = -int(1e9)

        for i in range(K - 1, N):
            for j in range(K - 1, N):
                temp = prefix[i][j]
                if i - K >= 0:
                    temp -= prefix[i - K][j]
                if j - K >= 0:
                    temp -= prefix[i][j - K]
                if i - K >= 0 and j - K >= 0:
                    temp += prefix[i - K][j - K]
                ans = max(ans, temp)

        return ans


# {
# Driver Code Starts


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        matrix = []
        for _ in range(n):
            matrix.append([int(x) for x in input().strip().split()])
        k = int(input())
        obj = Solution()
        print(obj.Maximum_Sum(matrix, n, k))
# } Driver Code Ends
