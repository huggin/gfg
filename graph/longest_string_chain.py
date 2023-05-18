# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3
from collections import deque


class Solution:
    def pred(self, s, t):
        if len(s) != len(t) - 1:
            return False
        i, j = 0, 0
        mismatch = 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
            else:
                mismatch += 1
                if mismatch > 1:
                    return False
            j += 1

        return i == len(s)

    def longestChain(self, N, words):
        # Code here
        adj = [[] for _ in range(N)]
        degree = [0] * N
        for i in range(N):
            for j in range(N):
                if i == j:
                    continue
                if self.pred(words[i], words[j]):
                    adj[i].append(j)
                    degree[j] += 1

        dist = [-1] * N
        q = deque()

        for i in range(N):
            if degree[i] == 0:
                q.append((i, 1))
                dist[i] = 1

        while len(q) > 0:
            v, d = q.popleft()
            for w in adj[v]:
                if dist[w] == -1:
                    dist[w] = d + 1
                    q.append((w, d + 1))

        return max(dist)


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        words = input().split()
        ob = Solution()
        res = ob.longestChain(N, words)
        print(res)
# } Driver Code Ends
