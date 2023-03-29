#User function Template for python3

class Solution:
    def invertBits(self,bin):
        #code here
        return 2 ** 32 - bin - 1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N=int(input())
        ob=Solution()
        print(ob.invertBits(N))
# } Driver Code Ends
