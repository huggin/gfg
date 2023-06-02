from typing import List


class Solution:
    def maxEqualSum(
        self, N1: int, N2: int, N3: int, S1: List[int], S2: List[int], S3: List[int]
    ) -> int:
        # code here
        s1 = set()
        s2 = set()
        total = 0
        for a in reversed(S1):
            total += a
            s1.add(total)

        total = 0
        for a in reversed(S2):
            total += a
            s2.add(total)

        total = 0
        ans = 0
        for a in reversed(S3):
            total += a
            if total in s1 and total in s2:
                ans = total

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
        a = IntArray().Input(3)

        S1 = IntArray().Input(a[0])

        S2 = IntArray().Input(a[1])

        S3 = IntArray().Input(a[2])

        obj = Solution()
        res = obj.maxEqualSum(a[0], a[1], a[2], S1, S2, S3)

        print(res)


# } Driver Code Ends
