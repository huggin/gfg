# User function Template for python3

from typing import List
import sys

sys.setrecursionlimit(20000)


class Solution:
    def dfs(self, v, adj):
        self.marked[v] = 1
        for w in adj[v]:
            if self.marked[w] == 0:
                if self.dfs(w, adj) == 3:
                    self.marked[v] = 3
                    return 3
            elif self.marked[w] == 1:
                self.marked[v] = 3
                return 3
            elif self.marked[w] == 3:
                self.marked[v] = 3
                return 3

        self.marked[v] = 2
        return 2

    def eventualSafeNodes(self, V: int, adj: List[List[int]]) -> List[int]:
        # code here
        self.marked = [0] * V
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
