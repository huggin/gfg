#User function Template for python3

class Solution:
    def winner(self, N):
        # code here
        if N % 2:
            return "Harvey"
        else:
            return "Mike"

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        
        ob = Solution()
        print(ob.winner(N))
# } Driver Code Ends
