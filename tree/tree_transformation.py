from typing import List


class Solution:
    def solve(self, N: int, p: List[int]) -> int:
        # code here
        adj = [[] for _ in range(N)]
        for i in range(1, N):
            adj[p[i]].append(i)

        ans = 1 if len(adj[0]) == 1 else 0
        for a in adj:
            if not a:
                ans += 1

        return max(N - 1 - ans, 0)


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

        p = IntArray().Input(N)

        obj = Solution()
        res = obj.solve(N, p)

        print(res)


# } Driver Code Ends
