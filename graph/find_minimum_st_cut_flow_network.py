# User function Template for python3
from collections import deque


class Solution:
    def bfs(self, s, t, n, parent):
        parent[:] = [-1] * n
        parent[s] = -2
        q = deque()
        q.append((s, 2**31))
        while q:
            v, flow = q.popleft()
            for w in range(n):
                if parent[w] != -1 or self.capacity[v][w] == 0:
                    continue
                parent[w] = v
                nf = min(flow, self.capacity[v][w])
                if w == t:
                    return nf
                q.append((w, nf))

        return 0

    def minimumCut(self, A, S, T, N):
        # code here
        self.capacity = [[e for e in a] for a in A]
        flow = 0
        parent = [-1] * N

        new_flow = self.bfs(S, T, N, parent)
        while new_flow > 0:
            flow += new_flow
            curr = T
            while curr != S:
                prev = parent[curr]
                self.capacity[prev][curr] -= new_flow
                self.capacity[curr][prev] += new_flow
                curr = prev

            new_flow = self.bfs(S, T, N, parent)

        sources = set()
        marked = [0] * N
        marked[S] = 1
        q = deque()
        q.append(S)
        while q:
            v = q.popleft()
            sources.add(v)
            for w in range(N):
                if marked[w] == 0 and self.capacity[v][w] > 0:
                    q.append(w)
                    marked[w] = 1

        ans = []
        for v in sources:
            for w in range(N):
                if w not in sources and A[v][w] > 0:
                    ans.append(v)
                    ans.append(w)

        return ans if ans else [-1]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = []
        for i in range(N):
            l = list(map(int, input().strip().split()))
            A.append(l)
        S, T = map(int, input().strip().split())
        ob = Solution()
        res = ob.minimumCut(A, S, T, N)
        for each in res:
            print(each, end=" ")
        print()


# } Driver Code Ends
