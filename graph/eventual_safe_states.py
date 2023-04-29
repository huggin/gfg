# User function Template for python3

from typing import List


class Solution:
    def dfs(self, v, adj):
        self.marked[v] = 1
        for w in adj[v]:
            if self.marked[w] == 0:
                self.path[w] = v
                self.dfs(w, adj)
            elif self.marked[w] == 1:
                k = v
                while k != w:
                    self.marked[k] = 3
                    k = self.path[k]
                self.marked[w] = 3
            elif self.marked[w] == 3:
                k = v
                while k != -1 and self.marked[k] != 3:
                    self.marked[k] = 3
                    k = self.path[k]

        self.marked[v] = 2
        for w in adj[v]:
            if self.marked[w] == 3:
                self.marked[v] = 3
                break

    def eventualSafeNodes(self, V: int, adj: List[List[int]]) -> List[int]:
        # code here
        self.marked = [0] * V
        self.path = [-1] * V
        for i in range(V):
            if self.marked[i] == 0:
                self.dfs(i, adj)

        return [i for i in range(V) if self.marked[i] == 2]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        V, E = map(int, input().strip().split())
        adj = [[] for i in range(V)]
        for i in range(E):
            u, v = map(int, input().strip().split())
            adj[u].append(v)
        obj = Solution()
        ans = obj.eventualSafeNodes(V, adj)
        for nodes in ans:
            print(nodes, end=" ")
        print()


# } Driver Code Ends
