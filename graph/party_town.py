#User function Template for python3
from collections import deque

class Solution:
    def partyHouse(self, N, adj):
        # code here
        ans = N
        for i in range(1, N+1):
            dist = [-1] * (N + 1)
            dist[i] = 0
            q = deque()
            q.append(i)
            max_dist = 0
            while len(q) > 0:
                v = q.popleft()
                for w in adj[v]:
                    if dist[w] == -1:
                        dist[w] = dist[v] + 1
                        max_dist = max(max_dist, dist[w])
                        q.append(w)
            
            ans = min(ans, max_dist)
        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        adj = [[] for x in range(N+1)]
        for i in range(N-1):
            x, y = [int(a) for a in input().split()]
            adj[x].append(y)
            adj[y].append(x)
        
        ob = Solution()
        print(ob.partyHouse(N, adj))
# } Driver Code Ends
