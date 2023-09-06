class Solution:
    # Function to find a Mother Vertex in the Graph.
    def findMotherVertex(self, V, adj):
        # Code here
        visited = [0] * V

        def dfs(v, s):
            visited[v] = 1
            s.add(v)
            for w in adj[v]:
                if w not in s:
                    dfs(w, s)

        for v in range(V):
            s = set()
            if visited[v] == 0:
                dfs(v, s)
            if len(s) == V:
                return v

        return -1


# {
# Driver Code Starts
# Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)
if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        V, E = map(int, input().split())
        adj = [[] for i in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
        obj = Solution()
        ans = obj.findMotherVertex(V, adj)
        print(ans)
# } Driver Code Ends
