class Solution:
    def isEulerCircuitExist(self, V, adj):
        # Code here
        ans = 0
        for i in range(V):
            if len(adj[i]) % 2 == 1:
                ans += 1

        return 2 if ans == 0 else 1 if ans == 2 else 0


# {
# Driver Code Starts


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        V, E = map(int, input().strip().split())
        adj = [[] for i in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)
        obj = Solution()
        ans = obj.isEulerCircuitExist(V, adj)
        print(ans)
# } Driver Code Ends
