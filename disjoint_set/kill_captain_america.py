# User function Template for python3
from collections import Counter, deque


class UF:
    def __init__(self, n):
        self.n = n
        self.parent = [i for i in range(n)]

    def find(self, k):
        ok = k
        while self.parent[k] != k:
            k = self.parent[k]
        while self.parent[ok] != k:
            pk = self.parent[ok]
            self.parent[ok] = k
            ok = pk
        return k

    def union(self, x, y):
        # px = self.find(x)
        py = self.find(y)
        self.parent[x] = py

    def getStart(self):
        cnt = Counter()
        for k in range(self.n):
            cnt[self.find(k)] += 1

        for i in range(self.n):
            if cnt[i] == self.n:
                return i

        return -1


class Solution:
    def captainAmerica(self, N, M, V):
        # code here
        _ = M
        v = [[] for _ in range(N)]

        uf = UF(N)
        for edge in V:
            v[edge[0] - 1].append(edge[1] - 1)
            uf.union(edge[0] - 1, edge[1] - 1)

        start = uf.getStart()
        if start == -1:
            return 0

        Q = deque()
        marked = [0 for _ in range(N)]
        marked[start] = 1
        Q.append(start)
        ans = 1
        while len(Q) > 0:
            k = Q.popleft()
            for w in v[k]:
                if not marked[w]:
                    ans += 1
                    marked[w] = 1
                    Q.append(w)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    ob = Solution()
    t = int(input())
    for _ in range(t):
        N, M = map(int, input().split())
        V = list()
        for i in range(0, M):
            l = list(map(int, input().split()))
            V.append(l)
        ans = ob.captainAmerica(N, M, V)
        print(ans)


# } Driver Code Ends
