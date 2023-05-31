class Solution:
    def dfs(self, adj, v, marked):
        marked[v] = 1
        for w in adj[v]:
            if marked[w] == 0:
                self.dfs(adj, w, marked)
        self.post.append(v)

    # Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        # Code here
        self.post = []
        marked = [0] * V
        for v in range(V):
            if marked[v] == 0:
                self.dfs(adj, v, marked)

        return list(reversed(self.post))


# {
# Driver Code Starts
# Driver Program

import sys

sys.setrecursionlimit(10**6)


def check(graph, N, res):
    if N != len(res):
        return False
    map = [0] * N
    for i in range(N):
        map[res[i]] = i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        e, N = list(map(int, input().strip().split()))
        adj = [[] for i in range(N)]

        for i in range(e):
            u, v = map(int, input().split())
            adj[u].append(v)

        ob = Solution()

        res = ob.topoSort(N, adj)

        if check(adj, N, res):
            print(1)
        else:
            print(0)
# Contributed By: Harshit Sidhwa

# } Driver Code Ends
