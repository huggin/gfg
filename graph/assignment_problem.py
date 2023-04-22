# User function Template for python3
from collections import deque


class Solution:
    def assignmentProblem(self, Arr, N):
        # code here
        INF = int(1e9)
        n = 2 * N + 2

        f = [[0 for _ in range(n)] for _ in range(n)]
        s = n - 2
        t = n - 1
        cost = 0
        while True:
            dist = [INF] * n
            dist[s] = 0
            p = [-1] * n
            inq = [False] * n
            q = deque()
            q.append(s)

            while len(q) > 0:
                v = q.popleft()
                inq[v] = False
                if v == s:
                    for i in range(N):
                        if f[v][i] == 0:
                            dist[i] = 0
                            p[i] = v
                            inq[i] = True
                            q.append(i)
                elif v < N:
                    for i in range(N, N + N):
                        if f[v][i] < 1 and dist[i] > dist[v] + Arr[v * N + i - N]:
                            dist[i] = dist[v] + Arr[v * N + i - N]
                            p[i] = v
                            if not inq[i]:
                                inq[i] = True
                                q.append(i)
                elif v < N + N:
                    for i in range(N):
                        if f[v][i] < 0 and dist[i] > dist[v] - Arr[i * N + v - N]:
                            dist[i] = dist[v] - Arr[i * N + v - N]
                            p[i] = v
                            if not inq[i]:
                                inq[i] = True
                                q.append(i)

            curcost = INF
            for i in range(N):
                if f[i+N][t] == 0 and dist[i+N] < curcost:
                    curcost = dist[i+N]
                    p[t] = i + N

            if curcost == INF:
                break
            cost += curcost

            cur = t
            while cur != -1:
                pre = p[cur]
                if pre != -1:
                    f[pre][cur] = 1
                    f[cur][pre] = -1
                cur = pre

        return cost


# {
 # Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        Arr = list(map(int, input().split()))

        ob = Solution()
        print(ob.assignmentProblem(Arr, N))
# } Driver Code Ends
