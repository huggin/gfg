# User function Template for python3

from typing import List
from collections import defaultdict
import heapq
import sys


class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        # Your code here
        g = [[] for _ in range(n)]
        for r in roads:
            g[r[0]].append((r[1], r[2]))
            g[r[1]].append((r[0], r[2]))

        pq = []
        heapq.heappush(pq, (0, 0))
        dist = defaultdict(lambda: -1)
        dist[0] = 0
        path = [0] * n
        path[0] = 1

        while len(pq) > 0:
            d, node = heapq.heappop(pq)
            for neighbour, weight in g[node]:
                if dist[neighbour] == -1:
                    dist[neighbour] = d + weight
                    path[neighbour] = path[node]
                    heapq.heappush(pq, (dist[neighbour], neighbour))
                elif dist[neighbour] == d + weight:
                    path[neighbour] += path[node]

        return path[n - 1]


# {
# Driver Code Starts
# Initial Template for Python 3


class IntArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())

        adj = []

        for i in range(m):
            tmp = []
            x, y, z = map(int, input().split())
            tmp.append(x)
            tmp.append(y)
            tmp.append(z)
            adj.append(tmp)

        obj = Solution()
        res = obj.countPaths(n, adj)

        print(res)


# } Driver Code Ends
