# User function Template for python3
from typing import List
import heapq


class Solution:
    def CheapestFLight(self, n, flights, src, dst, k):
        pq = []

        g = [[] for _ in range(n)]
        for f in flights:
            g[f[0]].append((f[1], f[2]))

        dist = [[-1 for _ in range(k + 2)] for _ in range(n)]
        dist[src][0] = 0

        pq.append((0, 0, src))
        ans = -1

        while len(pq) > 0:
            price, stop, v = heapq.heappop(pq)

            if v == dst:
                if ans == -1 or ans > price:
                    ans = price
            if stop > k:
                continue
            for w, weight in g[v]:
                if dist[w][stop + 1] == -1 or dist[w][stop + 1] > price + weight:
                    dist[w][stop + 1] = price + weight
                    heapq.heappush(pq, (dist[w][stop + 1], stop + 1, w))

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    test_cases = int(input())
    for _ in range(test_cases):
        n, edge = map(int, input().split())
        flights = []
        for _ in range(edge):
            temp = list(map(int, input().split()))
            flights.append(temp[:])
        src = int(input())
        dst = int(input())
        k = int(input())
        obj = Solution()
        res = obj.CheapestFLight(n, flights, src, dst, k)
        print(res)


# } Driver Code Ends
