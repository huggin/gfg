from typing import List
from collections import Counter


class Solution:
    def isFrequencyUnique(self, n: int, arr: List[int]) -> bool:
        # code here
        c = Counter(arr)
        prev = -1
        for _, v in c.most_common():
            if v == prev:
                return False
            prev = v

        return True


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
        res = obj.isFrequencyUnique(n, arr)

        result_val = 1 if res else 0
        print(result_val)

# } Driver Code Ends
