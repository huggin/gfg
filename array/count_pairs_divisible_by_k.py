# Template for python3


class Solution:
    def countKdivPairs(self, arr, n, k):
        # code here
        c = [0] * k
        for a in arr:
            c[a % k] += 1

        ans = 0
        for i in range(k):
            if k - i < i:
                continue
            if i + i == k or i == 0:
                ans += c[i] * (c[i] - 1) // 2
            else:
                ans += c[i] * c[k - i]

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        a = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.countKdivPairs(a, n, k))
# } Driver Code Ends
