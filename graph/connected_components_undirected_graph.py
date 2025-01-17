class Solution:
    # Function to return connected components of the graph
    def connectedcomponents(self, n, edges):
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        ans = []
        visited = [0] * n

        def dfs(u, group):
            group.append(u)
            for v in g[u]:
                if visited[v] == 0:
                    visited[v] = 1
                    dfs(v, group)

        for i in range(n):
            if visited[i] == 0:
                group = []
                visited[i] = 1
                dfs(i, group)
                ans.append(group)
        return ans


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        e = int(input())  # Number of edges
        v = int(input())  # Number of vertices

        # Input edges
        edges = []
        for _ in range(e):
            edges.append(list(map(int, input().split())))

        obj = Solution()
        res = obj.connectedcomponents(v, edges)
        # Sort each component in ascending order
        for component in res:
            component.sort()

        # Sort the components based on the first element of each component
        res.sort(key=lambda x: x[0])
        # Print each component on a new line
        for component in res:
            print(" ".join(map(str, component)))
        print("~")

# } Driver Code Ends
