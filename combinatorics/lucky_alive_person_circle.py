#User function Template for python3
class Solution:
    def find(self,N):
        # code here
        if N == 1: 
            return 1
        if N % 2 == 0:
            return 2 * self.find(N/2) - 1
        else:
            return 2 * self.find(N//2) + 1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        ob = Solution()
        print(ob.find(N))
# } Driver Code Ends
