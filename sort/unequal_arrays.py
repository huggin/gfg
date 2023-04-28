from typing import List


class Solution:
    def solve(self, N: int, A: List[int], B: List[int]) -> int:
        # code here
        if sum(A) != sum(B):
            return -1
        A.sort(key=lambda elem: (elem % 2, elem))
        B.sort(key=lambda elem: (elem % 2, elem))

        total = 0
        for i in range(N):
            if A[i] % 2 != B[i] % 2:
                return -1
            if A[i] > B[i]:
                total += A[i] - B[i]

        return total // 2


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

        B = IntArray().Input(N)

        obj = Solution()
        res = obj.solve(N, A, B)

        print(res)


# } Driver Code Ends
