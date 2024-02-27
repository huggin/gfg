from typing import List
from functools import lru_cache


class Solution:
    def findNthNumber(self, n: int, k: int) -> int:
        # code here
        @lru_cache(maxsize=None)
        def f(s, i, n, k, equal):
            if k == 0 or i == n:
                return 1
            ans = 0
            if not equal:
                return f(s, i + 1, n, k - 1, False) + f(s, i + 1, n, k, False)
            else:
                if s[i] == "1":
                    ans += f(s, i + 1, n, k - 1, True) + f(s, i + 1, n, k, False)
                else:
                    ans += f(s, i + 1, n, k, True)

            return ans

        def count(m):
            s = str(bin(m))[2:]
            n = len(s)
            return f(s, 0, n, k, True)

        lo, hi = 1, 1 << 63
        ans = -1
        while lo <= hi:
            mi = (lo + hi) >> 1
            d = count(mi)
            if d >= n:
                ans = mi
                hi = mi - 1
            else:
                lo = mi + 1

        return ans


# {
# Driver Code Starts


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())

        obj = Solution()
        res = obj.findNthNumber(n, k)

        print(res)


# } Driver Code Ends
