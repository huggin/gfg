#User function Template for python3

class Solution:
    def findMaxSum(self,n,m,mat):
        #code here
        if n < 3 or m < 3:
            return -1
        ans = -1
        for i in range(1, n-1):
            curr = mat[i-1][0] + mat[i-1][1] + mat[i-1][2]
            curr += mat[i][1]
            curr += mat[i+1][0] + mat[i+1][1] + mat[i+1][2]
            ans = max(curr, ans)
            for j in range(2, m-1):
                curr += mat[i][j] - mat[i][j-1]
                curr += mat[i-1][j+1] - mat[i-1][j-2]
                curr += mat[i+1][j+1] - mat[i+1][j-2]
                ans = max(curr, ans)
        
        return ans
                

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
      
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N,M=map(int,input().strip().split(" "))
        Mat=[]
        for i in range(N):
            B=list(map(int,input().strip().split(" ")))
            Mat.append(B)
        ob=Solution()
        ans=ob.findMaxSum(N,M,Mat)
        print(ans) 
# } Driver Code Ends
