#User function Template for python3
import bisect
import sys

class Solution:
    def closestToZero (self,arr, n):
        # your code here
        ans = -1
        diff = sys.maxsize
        arr.sort()
        for i in range(n):
            idx = bisect.bisect(arr, -arr[i])
            if idx < n and i != idx and (abs(arr[i] + arr[idx]) < diff or arr[i] + arr[idx] == diff): 
                ans = arr[i] + arr[idx]
                diff = abs(ans)
            elif idx > 0 and i != idx - 1 and (abs(arr[i] + arr[idx-1]) < diff or arr[i] + arr[idx-1] == diff):
                ans = arr[i] + arr[idx-1]
                diff = abs(ans)
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int (input ())
for tc in range(t):
    n = int (input ())
    arr = list(map(int, input().split()))
    ob = Solution()
    print (ob.closestToZero (arr, n))
# } Driver Code Ends
