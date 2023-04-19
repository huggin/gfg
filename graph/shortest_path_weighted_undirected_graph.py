# User function Template for python3
import heapq


class Solution:
    def shortestPath(self, n, m, edges):
        # Code here
        pq = []

        g = [[] for _ in range(n + 1)]
        for e in edges:
            g[e[0]].append((e[1], e[2]))
            g[e[1]].append((e[0], e[2]))

        src, dst = 1, n
        path = [-1] * (n + 1)
        path[1] = 0

        heapq.heappush(pq, (0, src, -1))
        while len(pq) > 0:
            weight, node, prev = heapq.heappop(pq)
            if path[node] == -1:
                path[node] = prev

            for e in g[node]:
                if path[e[0]] == -1:
                    heapq.heappush(pq, (e[1] + weight, e[0], node))

        if path[dst] == -1:
            return [-1]

        ans = []

        while dst != 0:
            ans.append(dst)
            dst = path[dst]

        return reversed(ans)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = list(map(int, input().split()))
        edges = []
        for i in range(m):
            node1, node2, weight = list(map(int, input().split()))
            edges.append([node1, node2, weight])
        obj = Solution()
        ans = obj.shortestPath(n, m, edges)
        for e in ans:
            print(e, end=" ")
        print()
# } Driver Code Ends
