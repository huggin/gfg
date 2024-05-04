from typing import List
import heapq


class Solution:
    def maximumSum(self, N: int, A: List[int]) -> int:
        # code here
        ans = 0 if N % 2 == 0 else A[N // 2]
        pq = []
        for i in range(N // 2):
            if len(pq) < i + 1:
                heapq.heappush(pq, A[i])
            elif pq[0] < A[i]:
                heapq.heapreplace(pq, A[i])
            if len(pq) < i + 1:
                heapq.heappush(pq, A[N - 1 - i])
            elif pq[0] < A[N - 1 - i]:
                heapq.heapreplace(pq, A[N - 1 - i])

        return ans + sum(pq)


# {
# Driver Code Starts


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

        N = int(input())

        A = IntArray().Input(N)

        obj = Solution()
        res = obj.maximumSum(N, A)

        print(res)


# } Driver Code Ends
