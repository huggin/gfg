# User function Template for python3


class Solution:
    # Function to return list of integers that form the boundary
    # traversal of the matrix in a clockwise manner.
    def BoundaryTraversal(self, matrix, n, m):
        # code here
        ans = []

        if n == 1:
            for i in range(m):
                ans.append(matrix[0][i])
            return ans
        if m == 1:
            for i in range(n):
                ans.append(matrix[i][0])
            return ans

        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]

        k = 0
        x, y = 0, 0
        while len(ans) < 2 * (m + n - 2):
            ans.append(matrix[x][y])
            nx = x + dx[k]
            ny = y + dy[k]
            if nx >= n or ny >= m or ny < 0:
                k = (k + 1) % 4
                nx = x + dx[k]
                ny = y + dy[k]
            x, y = nx, ny

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().strip().split())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix = []
        for i in range(n):
            row = []
            for j in range(m):
                row.append(values[k])
                k += 1
            matrix.append(row)
        obj = Solution()
        ans = obj.BoundaryTraversal(matrix, n, m)
        for i in ans:
            print(i, end=" ")
        print()

# } Driver Code Ends
