#User function Template for python3
from collections import Counter

class Solution:
   
    #Function to sort the array according to frequency of elements.
    def sortByFreq(self,a,n):
        #code here
        c = Counter(a)
        a.sort(key=lambda x: (-c[x], x))
        return a


#{ 
 # Driver Code Starts
#Initial Template for Python 3

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


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        n=int(input())
        a = list(map(int, input().strip().split()))
        l = Solution().sortByFreq(a,n)
        print(*l)
# } Driver Code Ends
