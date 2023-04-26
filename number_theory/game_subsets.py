from typing import List


class Solution:
    def goodSubsets(self, n: int, arr: List[int]) -> int:
        # code here
        prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        m = len(prime)
        good = []
        for i in range(1 << m):
            temp = 1
            for j in range(m):
                if i & (1 << j):
                    temp *= prime[j]
            good.append(temp)

        good.sort()
        gs = set(good)
        M = 1000000007
        dict = {}
        dict[1] = 0
        one = 0
        for a in arr:
            if not a in gs:
                continue
            if a == 1:
                one += 1
            else:
                dict[a] = dict.get(a, 0) + 1

                for k, v in dict.copy().items():
                    if k * a in gs:
                        dict[k * a] = (dict.get(k * a, 0) + dict[k]) % M

        ans = 0
        for k, v in dict.items():
            ans = (ans + v) % M

        ans = ans * 2**one
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
        n = int(input())

        arr = IntArray().Input(n)

        obj = Solution()
        res = obj.goodSubsets(n, arr)

        print(res)


# } Driver Code Ends
