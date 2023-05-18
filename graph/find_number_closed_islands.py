# User function Template for python3
from collections import deque


class Solution:
    def closedIslands(self, matrix, N, M):
        # Code here
        q = deque()

        for i in range(N):
            if matrix[i][0] == 1:
                matrix[i][0] = 2
                q.append((i, 0))
            if matrix[i][M - 1] == 1:
                matrix[i][M - 1] = 2
                q.append((i, M - 1))
        for j in range(1, M - 1):
            if matrix[0][j] == 1:
                matrix[0][j] = 2
                q.append((0, j))
            if matrix[N - 1][j] == 1:
                matrix[N - 1][j] = 2
                q.append((N - 1, j))

        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]
        while len(q) > 0:
            x, y = q.popleft()
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if nx >= 0 and nx < N and ny >= 0 and ny < M and matrix[nx][ny] == 1:
                    matrix[nx][ny] = 2
                    q.append((nx, ny))

        ans = 0
        for i in range(N):
            for j in range(M):
                if matrix[i][j] == 1:
                    ans += 1
                    matrix[i][j] = 3
                    q.append((i, j))
                    while len(q) > 0:
                        x, y = q.popleft()
                        for k in range(4):
                            nx = x + dx[k]
                            ny = y + dy[k]
                            if (
                                nx >= 0
                                and nx < N
                                and ny >= 0
                                and ny < M
                                and matrix[nx][ny] == 1
                            ):
                                matrix[nx][ny] = 3
                                q.append((nx, ny))

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        N, M = map(int, input().split())
        matrix = []
        for i in range(N):
            nums = list(map(int, input().split()))
            matrix.append(nums)
        obj = Solution()
        print(obj.closedIslands(matrix, N, M))
# } Driver Code Ends
