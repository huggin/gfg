from typing import List


class Solution:
    def sumZeroMatrix(self, a: List[List[int]]) -> List[List[int]]:
        # code here
        n = len(a)
        m = len(a[0])

        def f(b):
            d = {}
            d[0] = -1
            curr = 0
            ans = 0
            x, y = 0, -1
            for i in range(m):
                curr += b[i]
                if curr in d:
                    if ans < i - d[curr]:
                        x, y = d[curr] + 1, i
                        ans = i - d[curr]
                else:
                    d[curr] = i

            return x, y

        ma = 0
        l, r, u, d = 0, 0, 0, 0

        a2 = [[0 for _ in range(m)] for _ in range(n)]
        for k in range(n):
            for i in range(k, n):
                for j in range(m):
                    a2[i][j] += a[i - k][j]
                x, y = f(a2[i])
                area = (y - x + 1) * (k + 1)

                if ma < area or (ma == area and (x < l or x == l and y < r)):
                    ma = area
                    l, r, u, d = x, y, i - k, i

        ans = [[0 for _ in range(r - l + 1)] for _ in range(d - u + 1)]
        for i in range(u, d + 1):
            for j in range(l, r + 1):
                ans[i - u][j - l] = a[i][j]

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
        nm = IntArray().Input(2)

        a = IntMatrix().Input(nm[0], nm[1])

        obj = Solution()
        res = obj.sumZeroMatrix(a)
        if len(res) == 0:
            print(-1)
        else:
            IntMatrix().Print(res)


# } Driver Code Ends
