# User function Template for python3
from collections import deque


class Solution:
    def isTree(self, n, m, edges):
        # Code here
        if n == 1 and m == 0:
            return 1
        if m != n - 1:
            return 0
        g = [[] for _ in range(n)]
        used = [0] * n
        for e in edges:
            g[e[0]].append(e[1])
            g[e[1]].append(e[0])
            used[e[0]] = 1
            used[e[1]] = 1

        for i in range(n):
            if used[i] == 0:
                return 0

        mark = [0] * n
        q = deque()
        q.append((-1, 0))
        mark[0] = 1
        while len(q) > 0:
            prev, u = q.popleft()
            for v in g[u]:
                if v == prev:
                    continue
                if mark[v] == 1:
                    return 0
                q.append((u, v))
                mark[v] = 1

        return 1


# {
# Driver Code Starts
# Initial Template for Python 3

for _ in range(int(input())):
    n, m = [int(i) for i in input().split()]
    edges = []
    for i in range(m):
        a, b = map(int, input().split())
        edges.append([a, b])

    ob = Solution()
    print(ob.isTree(n, m, edges))
# } Driver Code Ends
