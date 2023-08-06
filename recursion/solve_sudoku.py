# User function Template for python3


class Solution:
    # Function to find a solved Sudoku.
    def SolveSudoku(self, grid):
        a = []
        for i in range(9):
            for j in range(9):
                if grid[i][j] == 0:
                    a.append((i, j))

        n = len(a)

        def dfs(k):
            if k == n:
                return True
            used = [0] * 10
            for i in range(9):
                if grid[a[k][0]][i] != 0:
                    used[grid[a[k][0]][i]] = 1
                if grid[i][a[k][1]] != 0:
                    used[grid[i][a[k][1]]] = 1

            ii, jj = a[k][0] // 3, a[k][1] // 3
            for i in range(3 * ii, 3 * ii + 3):
                for j in range(3 * jj, 3 * jj + 3):
                    if grid[i][j] != 0:
                        used[grid[i][j]] = 1

            for idx in range(1, 10):
                if used[idx] == 0:
                    grid[a[k][0]][a[k][1]] = idx
                    if dfs(k + 1):
                        return True
                    grid[a[k][0]][a[k][1]] = 0

            return False

        return dfs(0)

    # Function to print grids of the Sudoku.
    def printGrid(self, arr):
        # Your code here
        for low in arr:
            for item in low:
                print(item, end=" ")
