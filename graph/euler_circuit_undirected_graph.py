class Solution:
    def isEularCircuitExist(self, V, adj):
        # Code here
        for i in range(V):
            degree = len(adj[i])
            if degree % 2 == 1:
                return 0
        return 1


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
            adj[v].append(u)
        obj = Solution()
        ans = obj.isEularCircuitExist(V, adj)
        if ans:
            print("1")
        else:
            print("0")

# } Driver Code Ends
