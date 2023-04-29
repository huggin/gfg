# User function Template for python3
from collections import deque


class Solution:
    def shortestPath(self, edges, n, m, src):
        # code here
        g = [[] for _ in range(n)]
        for e in edges:
            g[e[0]].append(e[1])
            g[e[1]].append(e[0])

        dist = [-1] * n
        dist[src] = 0

        q = deque()
        q.append((src, 0))

        while len(q) > 0:
            curr, d = q.popleft()
            for nb in g[curr]:
                if dist[nb] == -1:
                    dist[nb] = d + 1
                    q.append((nb, d + 1))

        return dist


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n, m = map(int, input().strip().split())
        edges = []
        for i in range(m):
            li = list(map(int, input().split()))
            edges.append(li)
        src = int(input())
        ob = Solution()
        ans = ob.shortestPath(edges, n, m, src)
        for i in ans:
            print(i, end=" ")
        print()
        tc -= 1
# } Driver Code Ends
