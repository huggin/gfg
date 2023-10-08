from typing import List


class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        # Code
        cnt = {}
        last = 2
        n = len(grid)
        visited = [[0 for _ in range(n)] for _ in range(n)]

        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]
        ans = 0

        def dfs(i, j, nodes):
            visited[i][j] = 1
            nodes.append((i, j))
            ans = 1
            for k in range(4):
                ni = i + dx[k]
                nj = j + dy[k]
                if (
                    ni >= 0
                    and ni < n
                    and nj >= 0
                    and nj < n
                    and visited[ni][nj] == 0
                    and grid[ni][nj] == 1
                ):
                    ans += dfs(ni, nj, nodes)
            return ans

        for i in range(n):
            for j in range(n):
                if visited[i][j] == 0 and grid[i][j] == 1:
                    nodes = []
                    count = dfs(i, j, nodes)
                    ans = max(ans, count)
                    cnt[last] = count
                    for node in nodes:
                        grid[node[0]][node[1]] = last
                    last += 1

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    adj = set()
                    for k in range(4):
                        ni = i + dx[k]
                        nj = j + dy[k]
                        if (
                            ni >= 0
                            and ni < n
                            and nj >= 0
                            and nj < n
                            and grid[ni][nj] != 0
                        ):
                            adj.add(grid[ni][nj])
                    ans2 = 1
                    for id in adj:
                        ans2 += cnt[id]

                    ans = max(ans, ans2)

        return ans


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
        res = obj.largestIsland(grid)

        print(res)
# } Driver Code Ends
