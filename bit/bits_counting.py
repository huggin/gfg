from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        # code here
        ans = []
        for i in range(n + 1):
            k = i
            t = 0
            while k > 0:
                t += 1
                k &= k - 1
            ans.append(t)
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

        obj = Solution()
        res = obj.countBits(n)

        IntArray().Print(res)
        print("~")

# } Driver Code Ends
