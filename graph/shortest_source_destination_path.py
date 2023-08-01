# User function Template for python3
from collections import deque


class Solution:
    def shortestDistance(self, N, M, A, X, Y):
        # code here
        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]
        q = deque()
        q.append((0, 0, 0))
        while q:
            x, y, d = q.popleft()
            if x == X and y == Y:
                return d

            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if nx >= 0 and nx < N and ny >= 0 and ny < M and A[nx][ny] == 1:
                    A[nx][ny] = 0
                    q.append((nx, ny, d + 1))

        return -1


# {
# Driver Code Starts

# Initial Template for Python 3

import math

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, M = map(int, input().strip().split())
        a = []
        for i in range(N):
            s = list(map(int, input().strip().split()))
            a.append(s)
        x, y = map(int, input().strip().split())
        ob = Solution()
        print(ob.shortestDistance(N, M, a, x, y))

# } Driver Code Ends
