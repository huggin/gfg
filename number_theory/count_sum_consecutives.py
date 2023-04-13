#User function Template for python3
import math

class Solution:
    def getCount(self, N):
        # code here 
        if N == 1:
            return 0
        ans = 0
        if N % 2 == 1:
            ans = 1
            for i in range(3, int(math.sqrt(N))+1, 2):
                if N % i == 0:
                    ans += 1
                    if i * i != N:
                        ans += 1
        
        else:
            for i in range(2, int(math.sqrt(N))+1):
                if N % i == 0 and (N // i % 2 == 1 or i % 2 == 1):
                    ans += 1
                    # ans += 2, bad test for example, 20
            
        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.getCount(N))
# } Driver Code Ends
