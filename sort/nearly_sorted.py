#User function Template for python3
import heapq

class Solution:
    
    #Function to return the sorted array.
    def nearlySorted(self,a,n,k):
        
        # code here
        h = []
        ans = []
        for i in range(k+1):
            heapq.heappush(h, a[i])
        
        j = k+1
        while len(ans) != n:
            ans.append(h[0])
            heapq.heappop(h)

            if j < n:
                heapq.heappush(h, a[j])
                j += 1
        
        return ans
        

#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys
import heapq
from collections import  defaultdict

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n,k = map(int,input().strip().split())
        a = list(map(int,input().strip().split()))
        ob=Solution()
        print(*ob.nearlySorted(a,n,k))

# } Driver Code Ends
