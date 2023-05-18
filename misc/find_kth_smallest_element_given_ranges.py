from typing import List


class Solution:
    def interval(self, r1, r2):
        if r1[0] > r2[1] or r1[1] < r2[0]:
            return False
        return True

    def kthSmallestNum(
        self, n: int, ranges: List[List[int]], q: int, queries: List[int]
    ) -> List[int]:
        # code here
        ranges.sort()
        nr = []
        for r in ranges:
            temp = r
            while len(nr) > 0 and self.interval(temp, nr[-1]):
                temp = [min(nr[-1][0], r[0]), max(nr[-1][1], r[1])]
                nr.pop()
            nr.append(temp)

        ans = []
        for query in queries:
            for r in nr:
                if query <= r[1] - r[0] + 1:
                    ans.append(r[0] + query - 1)
                    query = 0
                    break
                else:
                    query -= r[1] - r[0] + 1

            if query != 0:
                ans.append(-1)

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
        n = int(input())

        ranges = IntMatrix().Input(n, 2)

        q = int(input())

        queries = IntArray().Input(q)

        obj = Solution()
        res = obj.kthSmallestNum(n, ranges, q, queries)

        IntArray().Print(res)


# } Driver Code Ends
