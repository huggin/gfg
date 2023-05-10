# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def parent(self, p, v):
        while p[v] != v:
            p[v] = p[p[v]]
            v = p[v]
        return v

    def merge(self, parent, count, v, w):
        pv = self.parent(parent, v)
        pw = self.parent(parent, w)
        if count[pv] < count[pw]:
            parent[pv] = pw
            count[pw] += count[pv]
        else:
            parent[pw] = pv
            count[pv] += count[pw]

    def Solve(self, n, adj):
        # Code here
        m = len(adj)
        if m < n - 1:
            return -1

        parent = [i for i in range(n)]
        count = [1 for _ in range(n)]
        for e in adj:
            self.merge(parent, count, e[0], e[1])

        parts = 0
        for i in range(n):
            if parent[i] == i:
                parts += 1

        return parts - 1


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = list(map(int, input().split()))
        adj = [list(map(int, input().split())) for _ in range(m)]
        ob = Solution()
        res = ob.Solve(n, adj)
        print(res)
# } Driver Code Ends
