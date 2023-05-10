from typing import List
from collections import deque


class Solution:
    def MaxConnection(self, grid: List[List[int]]) -> int:
        # code here
        n = len(grid)
        m = len(grid[0])
        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]
        time = 1
        d = {}
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    time += 1
                    q = deque()
                    cnt = 0
                    q.append((i, j))
                    while len(q) > 0:
                        x, y = q.popleft()
                        cnt += 1
                        grid[x][y] = time
                        for k in range(4):
                            nx = x + dx[k]
                            ny = y + dy[k]
                            if not (nx >= 0 and nx < n and ny >= 0 and ny < m):
                                continue
                            if grid[nx][ny] == 1:
                                grid[nx][ny] = time
                                q.append((nx, ny))
                    d[time] = cnt

        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    cnt = 1
                    neighbor = set()
                    for k in range(4):
                        x = i + dx[k]
                        y = j + dy[k]
                        if not (x >= 0 and x < n and y >= 0 and y < m):
                            continue

                        if grid[x][y] != 0 and grid[x][y] not in neighbor:
                            cnt += d[grid[x][y]]
                            neighbor.add(grid[x][y])

                    ans = max(ans, cnt)
        return ans if ans != 0 else n * m


# {
# Driver Code Starts
class IntMatrix:
    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        # matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        grid = IntMatrix().Input(n, n)

        obj = Solution()
        res = obj.MaxConnection(grid)

        print(res)


# } Driver Code Ends
