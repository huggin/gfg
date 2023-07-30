# User function Template for python3

from typing import List
from queue import Queue


class Solution:
    # Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, V: int, adj: List[List[int]]) -> List[int]:
        # code here
        q = Queue()
        q.put(0)
        marked = [0] * V
        marked[0] = 1
        ans = []
        while not q.empty():
            v = q.get()
            ans.append(v)
            for w in adj[v]:
                if marked[w] == 0:
                    marked[w] = 1
                    q.put(w)

        return ans


# {
# Driver Code Starts


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        V, E = map(int, input().split())
        adj = [[] for i in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
        ob = Solution()
        ans = ob.bfsOfGraph(V, adj)
        for i in range(len(ans)):
            print(ans[i], end=" ")
        print()


# } Driver Code Ends
