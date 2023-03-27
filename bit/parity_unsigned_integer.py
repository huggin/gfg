#User function Template for python3

class Solution:
    def computeParity(self, N):
        # code here 
        ans = 0
        while N:
            ans += 1
            N &= N-1

        return "odd" if ans % 2 else "even"
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.computeParity(N))
# } Driver Code Ends
