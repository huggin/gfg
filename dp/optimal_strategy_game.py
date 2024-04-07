# User function Template for python3
from functools import lru_cache
import sys

sys.setrecursionlimit(1000001)


# Function to find the maximum possible amount of money we can win.
class Solution:
    def optimalStrategyOfGame(self, n, arr):
        # code here
        @lru_cache(None)
        def f(i, j):
            if i == j:
                return arr[i]
            return max(arr[i] - f(i + 1, j), arr[j] - f(i, j - 1))

        return (sum(arr) + f(0, n - 1)) // 2


# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == "__main__":
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.optimalStrategyOfGame(n, arr))

# } Driver Code Ends
