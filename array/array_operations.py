from typing import List


class Solution:
    def arrayOperations(self, n: int, arr: List[int]) -> int:
        # code here
        zero = False
        cnt = 0
        start = False
        for i in range(n):
            if arr[i] == 0:
                zero = True
                start = False
            else:
                if not start:
                    cnt += 1
                    start = True

        return -1 if not zero else cnt
        # return 1 if not zero else cnt


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
        res = obj.arrayOperations(n, arr)

        print(res)


# } Driver Code Ends
