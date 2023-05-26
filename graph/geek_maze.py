# User function Template for python3
# Caution: Bug in test cases
from collections import deque


def numberOfCells(n, m, r, c, u, d, mat):
    # code here
    if mat[r][c] == "#":
        return 0

    marked = [[0 for _ in range(m)] for _ in range(n)]
    marked[r][c] = 1

    q = deque()
    q.append((r, c, u, d))

    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    du = [0, 0, -1, 0]
    dd = [0, 0, 0, -1]

    ans = 0
    while len(q):
        x, y, u, d = q.popleft()
        ans += 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            nu = u + du[i]
            nd = d + dd[i]
            if not (nx >= 0 and nx < n and ny >= 0 and ny < m and nu >= 0 and nd >= 0):
                continue
            if mat[nx][ny] == "#" or marked[nx][ny] == 1:
                continue

            marked[nx][ny] = 1
            if i == 0 or i == 1:
                q.appendleft((nx, ny, nu, nd))
            else:
                q.append((nx, ny, nu, nd))
    return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(int(input()))

    for tcs in range(t):
        n, m, r, c, u, d = [int(x) for x in input().split()]

        mat = []

        for i in range(n):
            matele = [x for x in input()]
            mat.append(matele)

        print(numberOfCells(n, m, r, c, u, d, mat))
# } Driver Code Ends
