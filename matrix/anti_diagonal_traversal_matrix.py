# User function Template for python3


class Solution:
    def antiDiagonalPattern(self, matrix):
        # Code here
        n = len(matrix)
        ans = []

        for k in range(n):
            for i in range(k + 1):
                ans.append(matrix[i][k - i])

        for k in range(n, 2 * n - 1):
            for i in range(k - n + 1, n):
                ans.append(matrix[i][k - i])

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        inp = list(map(int, input().split()))
        matrix = []
        k = 0
        for i in range(n):
            row = []
            for j in range(n):
                row.append(inp[k])
                k += 1
            matrix.append(row)
        ob = Solution()
        ans = ob.antiDiagonalPattern(matrix)
        for i in ans:
            print(i, end=" ")
        print()


# } Driver Code Ends
