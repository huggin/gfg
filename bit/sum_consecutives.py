#User function Template for python3
class Solution:
    def canBeSumofConsec (self, n):
        # code here 
        return 1 if n & (n-1) else 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = int(input())
        
        ob = Solution()
        print(ob.canBeSumofConsec(n))
# } Driver Code Ends
