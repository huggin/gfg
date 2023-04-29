from typing import List
import heapq


class Solution:
    def powerfullInteger(self, n: int, intervals: List[List[int]], k: int) -> int:
        # code here
        intervals.sort()
        ans = -1
        heap = []

        for i in intervals:
            while len(heap) > 0 and heap[0] < i[0]:
                heapq.heappop(heap)
                if len(heap) >= k:
                    ans = heap[0]

            heapq.heappush(heap, i[1])
            if len(heap) >= k:
                ans = heap[0]

        while len(heap) > k:
            heapq.heappop(heap)
            ans = heap[0]
        return ans


# {
# Driver Code Starts
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


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        intervals = IntMatrix().Input(n, 2)

        k = int(input())

        obj = Solution()
        res = obj.powerfullInteger(n, intervals, k)

        print(res)


# } Driver Code Ends
