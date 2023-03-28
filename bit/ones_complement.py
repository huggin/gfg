#User function Template for python3
class Solution:
    def onesComplement(self,N):
        #code here
        ans = 0
        l = []
        while N:
            if N % 2:
                l.append(0)
            else:
                l.append(1)
            N //= 2 
            
        while len(l) > 0:
            ans = ans * 2 + l.pop()
        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())

        ob = Solution()
        print(ob.onesComplement(N))
# } Driver Code Ends
