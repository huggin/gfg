#User function Template for python3

from typing import List

class Solution:
    def makeBeautiful(self, arr: List[int]) -> List[int]:
        # code here
        s = []
        for a in arr:
            if len(s) > 0 and (s[-1] >= 0 and a < 0 or s[-1] < 0 and a >= 0):
                s.pop()
            else:
                s.append(a)

        return s
                

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        arr = list(map(int,input().split()))
        
        obj = Solution()
        res = obj.makeBeautiful(arr)
        print(*res)
# } Driver Code Ends
