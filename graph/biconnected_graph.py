# User function Template for python3


class Solution:
    def dfs(self, adj, v, p=-1):
        if self.ans:
            return
        self.marked[v] = 1
        self.low[v] = self.time
        self.tin[v] = self.time
        self.time += 1
        children = 0
        for w in adj[v]:
            if w == p:
                continue
            if self.marked[w]:
                self.low[v] = min(self.low[v], self.tin[w])
            else:
                self.dfs(adj, w, v)
                children += 1
                self.low[v] = min(self.low[v], self.low[w])
                if self.low[w] >= self.tin[v] and p != -1:
                    self.ans = True
                    return

        if p == -1 and children > 1:
            self.ans = True

    def biGraph(self, arr, n, e):
        # code here
        adj = [[] for _ in range(n)]
        for i in range(e):
            adj[arr[2 * i]].append(arr[2 * i + 1])
            adj[arr[2 * i + 1]].append(arr[2 * i])

        self.marked = [0 for _ in range(n)]
        self.tin = [-1 for _ in range(n)]
        self.low = [-1 for _ in range(n)]
        self.time = 0
        self.ans = False
        self.dfs(adj, 0)

        return 0 if self.ans or 0 in self.marked else 1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, e = map(int, input().split())
        arr = list(map(int, input().split()))

        ob = Solution()
        print(ob.biGraph(arr, n, e))
# } Driver Code Ends
