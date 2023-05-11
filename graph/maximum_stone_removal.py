# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def dfs(self, g, v, marked):
        marked[v] = 1
        for w in g[v]:
            if marked[w] == 0:
                self.dfs(g, w, marked)

    def maxRemove(self, adj, n):
        # Code here
        g = [[] for _ in range(n)]
        for i in range(n):
            for j in range(i + 1, n):
                if adj[i][0] == adj[j][0] or adj[i][1] == adj[j][1]:
                    g[i].append(j)
                    g[j].append(i)

        marked = [0] * n
        ans = 0
        for i in range(n):
            if not marked[i]:
                ans += 1
                self.dfs(g, i, marked)

        return n - ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        adj = [list(map(int, input().split())) for _ in range(n)]
        ob = Solution()
        res = ob.maxRemove(adj, n)
        print(res)
# } Driver Code Ends
