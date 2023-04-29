# User function Template for python3

from typing import List
from collections import deque


class Solution:
    def numberOfEnclaves(self, grid: List[List[int]]) -> int:
        # code here
        n = len(grid)
        m = len(grid[0])

        q = deque()

        for i in range(n):
            if grid[i][0] == 1:
                q.append((i, 0))
                grid[i][0] = 0

            if grid[i][m - 1] == 1:
                q.append((i, m - 1))
                grid[i][m - 1] = 0

        for j in range(m):
            if grid[0][j] == 1:
                q.append((0, j))
                grid[0][j] = 0
            if grid[n - 1][j] == 1:
                q.append((n - 1, j))
                grid[n - 1][j] = 0

        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]

        while len(q) > 0:
            x, y = q.popleft()
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny]:
                    grid[nx][ny] = 0
                    q.append((nx, ny))

        return sum(1 for line in grid for i in line if i == 1)


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    for _ in range(int(input())):
        n, m = map(int, input().strip().split())
        grid = []
        for i in range(n):
            grid.append([int(i) for i in input().strip().split()])

        obj = Solution()
        print(obj.numberOfEnclaves(grid))
# } Driver Code Ends
