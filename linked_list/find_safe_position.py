#User function Template for python3

class Solution:
    def safePos(self, n, k):
        # code here 
        ans = list(i+1 for i in range(n))
        start = 0
        while len(ans) > 1:
            start = (start + k - 1) % len(ans) 
            ans.pop(start)
        
        return ans[0]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n,k=map(int,input().split())
        
        ob = Solution()
        print(ob.safePos(n,k))
# } Driver Code Ends
