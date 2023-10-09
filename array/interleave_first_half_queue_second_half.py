from typing import List


class Solution:
    def rearrangeQueue(self, N: int, q: List[int]) -> List[int]:
        # code here
        ans = [0] * N
        for i in range(N):
            if i % 2 == 0:
                ans[i] = q[i // 2]
            else:
                ans[i] = q[i // 2 + N // 2]
        return ans


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

        q = IntArray().Input(N)

        obj = Solution()
        res = obj.rearrangeQueue(N, q)

        IntArray().Print(res)


# } Driver Code Ends
