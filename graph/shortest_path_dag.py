# User function Template for python3

from typing import List
import heapq


class Solution:
    def shortestPath(self, n: int, m: int, edges: List[List[int]]) -> List[int]:
        g = [[] for _ in range(n)]
        for e in edges:
            g[e[0]].append((e[1], e[2]))

        dist = [-1] * n
        dist[0] = 0
        pq = [(0, 0)]

        while pq:
            curr_dist, curr_node = heapq.heappop(pq)
            for nb, weight in g[curr_node]:
                curr = curr_dist + weight

                if dist[nb] == -1 or dist[nb] > curr:
                    dist[nb] = curr
                    heapq.heappush(pq, (curr, nb))

        return dist

# {
 # Driver Code Starts
# Initial Template for Python 3


class IntMatrix:
    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        # matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


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

        edges = IntMatrix().Input(m, 3)

        obj = Solution()
        res = obj.shortestPath(n, m, edges)

        IntArray().Print(res)
# } Driver Code Ends
