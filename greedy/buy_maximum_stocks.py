from typing import List


class Solution:
    def buyMaximumProducts(self, n: int, k: int, price: List[int]) -> int:
        # code here
        stock = []
        for i, p in enumerate(price):
            stock.append((p, i + 1))

        stock.sort()
        ans = 0
        for s in stock:
            if k >= s[1] * s[0]:
                ans += s[1]
                k -= s[1] * s[0]
            else:
                ans += k // s[0]
                break

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
        n, k = map(int, input().strip().split())

        price = IntArray().Input(n)

        obj = Solution()
        res = obj.buyMaximumProducts(n, k, price)

        print(res)


# } Driver Code Ends
