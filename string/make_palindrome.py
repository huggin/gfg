from typing import List
from collections import defaultdict


class Solution:
    def palindrome(self, s):
        n = len(s)
        for i in range(n // 2):
            if s[i] != s[n - 1 - i]:
                return False
        return True

    def makePalindrome(self, n: int, arr: List[str]) -> bool:
        # code here
        d = defaultdict(int)
        for a in arr:
            ra = a[::-1]
            if ra in d:
                d[ra] -= 1
            else:
                d[a] += 1

        one = ""
        left = 0
        for k, v in d.items():
            if v != 0:
                one = k
                left += 1

        if left > 1 or not self.palindrome(one):
            return False
        return True


# {
# Driver Code Starts
class StringArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = input().strip().split()  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        arr = StringArray().Input(n)

        obj = Solution()
        res = obj.makePalindrome(n, arr)

        result_val = "YES" if res else "NO"
        print(result_val)

# } Driver Code Ends
