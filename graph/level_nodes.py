# User function Template for python3
from collections import deque


class Solution:
    # Function to find the level of node X.
    def nodeLevel(self, V, adj, X):
        # code here
        q = deque()
        level = 0
        q.append(0)
        visited = [0] * V
        visited[0] = 1

        while q:
            n = len(q)
            for _ in range(n):
                v = q.popleft()
                if v == X:
                    return level
                for w in adj[v]:
                    if visited[w] == 0:
                        q.append(w)
                        visited[w] = 1
            level += 1

        return -1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        V, E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a, b = map(int, input().strip().split())
            adj[a].append(b)
            adj[b].append(a)
        X = int(input())
        ob = Solution()

        print(ob.nodeLevel(V, adj, X))
# } Driver Code Ends
