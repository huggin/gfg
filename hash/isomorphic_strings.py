# User function Template for python3


class Solution:
    # Function to check if two strings are isomorphic.
    def areIsomorphic(self, str1, str2):
        d = {}
        d2 = {}
        n = len(str1)
        if n != len(str2):
            return False
        for i in range(n):
            if str1[i] in d:
                if d[str1[i]] != str2[i]:
                    return False
            else:
                if str2[i] in d2:
                    return False
                d2[str2[i]] = str1[i]
                d[str1[i]] = str2[i]

        return True


# {
# Driver Code Starts
# Initial Template for Python 3

import atexit
import io
import sys
from collections import defaultdict

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
        s = str(input())
        p = str(input())
        ob = Solution()
        if ob.areIsomorphic(s, p):
            print(1)
        else:
            print(0)
# } Driver Code Ends
