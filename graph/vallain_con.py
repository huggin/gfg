# User function Template for python3
from collections import deque


class Solution:
    def minColour(self, N, M, mat):
        # code here
        adj = [[] for _ in range(N)]
        degree = [0] * N

        dist = [0] * N
        for m in mat:
            degree[m[0] - 1] += 1
            adj[m[1] - 1].append(m[0] - 1)

        q = deque()
        for i in range(N):
            if degree[i] == 0:
                q.append(i)

        while len(q) > 0:
            v = q.popleft()
            for w in adj[v]:
                degree[w] -= 1
                dist[w] = max(dist[w], dist[v] + 1)
                if degree[w] == 0:
                    q.append(w)

        return max(dist) + 1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, M = [int(x) for x in input().split()]
        mat = [[0] * 2 for y in range(M)]
        for i in range(M):
            arr = input().split()
            mat[i][0] = int(arr[0])
            mat[i][1] = int(arr[1])

        ob = Solution()
        print(ob.minColour(N, M, mat))
# } Driver Code Ends
