# User function Template for python3
from collections import deque


class Solution:
    def bfs(self, s, t, parent):
        q = deque()
        parent[s] = -2
        q.append((s, 100000))
        while len(q) > 0:
            v, flow = q.popleft()
            for w in self.adj[v]:
                if parent[w] == -1 and self.capacity[v][w] > 0:
                    parent[w] = v
                    nflow = min(flow, self.capacity[v][w])
                    if w == t:
                        return nflow
                    q.append((w, nflow))

        return 0

    def findMaxFlow(self, N, M, Edges):
        # code here
        self.adj = [[] for _ in range(N)]
        self.capacity = [[0 for _ in range(N)] for _ in range(N)]

        for e in Edges:
            self.adj[e[0] - 1].append(e[1] - 1)
            self.adj[e[1] - 1].append(e[0] - 1)
            self.capacity[e[0] - 1][e[1] - 1] += e[2]
            self.capacity[e[1] - 1][e[0] - 1] += e[2]

        flow = 0

        while True:
            parent = [-1] * N
            new_flow = self.bfs(0, N - 1, parent)
            if new_flow == 0:
                break
            flow += new_flow
            curr = N - 1
            while curr != 0:
                prev = parent[curr]
                self.capacity[prev][curr] -= new_flow
                self.capacity[curr][prev] += new_flow
                curr = prev

        return flow


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, M = map(int, input().strip().split())
        Edges = []
        input_line = list(map(int, input().strip().split()))
        for i in range(M):
            Edges.append(
                [input_line[3 * i], input_line[3 * i + 1], input_line[3 * i + 2]]
            )

        ob = Solution()
        ans = ob.findMaxFlow(N, M, Edges)
        print(ans)


# } Driver Code Ends
