# User function Template for python3
class Solution:
    # Function to return kth largest element from an array.
    def kthLargest(self, arr, k):
        # code here
        a = sorted(arr)
        return a[-k]


# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys
import heapq

# Contributed by : Nagendra Jha

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == "__main__":
    test_cases = int(input())
    for cases in range(test_cases):
        a = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.kthLargest(a, k))
        print("~")

# } Driver Code Ends
