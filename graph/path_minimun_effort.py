# User function Template for python3
import heapq


class Solution:
    def MinimumEffort(self, a):
        # code here
        pq = []
        heapq.heappush(pq, (0, 0, 0))
        n = len(a)
        m = len(a[0])
        dist = [[-1 for _ in range(m)] for _ in range(n)]

        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]
        dist[0][0] = 0

        while len(pq) > 0:
            curr_d, x, y = heapq.heappop(pq)
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if (
                    nx >= 0
                    and nx < n
                    and ny >= 0
                    and ny < m
                    and (
                        dist[nx][ny] == -1
                        or max(curr_d, abs(a[nx][ny] - a[x][y])) < dist[nx][ny]
                    )
                ):
                    dist[nx][ny] = max(curr_d, abs(a[nx][ny] - a[x][y]))
                    heapq.heappush(pq, (dist[nx][ny], nx, ny))

        return dist[n - 1][m - 1]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n, m = map(int, input().split())
        a = []
        for i in range(n):
            li = list(map(int, input().split()))
            a.append(li)
        ob = Solution()
        ans = ob.MinimumEffort(a)
        print(ans)
        tc -= 1
# } Driver Code Ends
