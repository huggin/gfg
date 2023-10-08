# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3

import heapq


class Solution:
    def Solve(self, n, adj):
        # Code here
        height = [[-1 for _ in range(n)] for _ in range(n)]
        height[0][0] = adj[0][0]
        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]

        pq = []
        heapq.heappush(pq, (height[0][0], 0, 0))
        while pq:
            h, x, y = heapq.heappop(pq)
            if x == n - 1 and y == n - 1:
                return h
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if (
                    nx >= 0
                    and nx < n
                    and ny >= 0
                    and ny < n
                    and (height[nx][ny] == -1 or height[nx][ny] > max(adj[nx][ny], h))
                ):
                    heapq.heappush(pq, (max(h, adj[nx][ny]), nx, ny))
                    height[nx][ny] = max(h, adj[nx][ny])

        return -1


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        adj = [list(map(int, input().split())) for _ in range(n)]
        ob = Solution()
        res = ob.Solve(n, adj)
        print(res)
# } Driver Code Ends
