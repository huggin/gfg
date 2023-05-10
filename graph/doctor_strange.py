# User function Template for python3
import sys

sys.setrecursionlimit(10000)


class Solution:
    def dfs(self, adj, v, prev=-1):
        self.it[v] = self.time
        self.low[v] = self.time
        self.time += 1
        children = 0
        for w in adj[v]:
            if w == prev:
                continue
            if self.it[w] == -1:
                children += 1
                self.dfs(adj, w, v)
                self.low[v] = min(self.low[v], self.low[w])
                if self.low[w] >= self.it[v] and prev != -1:
                    self.ans.add(v)
            else:
                self.low[v] = min(self.low[v], self.it[w])

        if children > 1 and prev == -1:
            self.ans.add(v)

    def doctorStrange(self, n, m, g):
        # Complete the function
        adj = [[] for _ in range(n)]
        for e in g:
            adj[e[0] - 1].append(e[1] - 1)
            adj[e[1] - 1].append(e[0] - 1)

        self.ans = set()
        self.time = 0
        self.low = [-1] * n
        self.it = [-1] * n
        for i in range(n):
            if self.it[i] == -1:
                self.dfs(adj, i)

        return len(self.ans)


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n, k = map(int, input().split())
    arr = []
    for i in range(k):
        li = list(map(int, input().split()))
        arr.append(li)
    ob = Solution()
    ans = ob.doctorStrange(n, k, arr)
    print(ans)
# } Driver Code Ends
