#User function Template for python3

def count(n):
    ans = 0
    while n:
        ans += 1
        n &= n-1
    return ans

class Solution:
    def bitMultiply(self, N):
        # code here
        return count(N) * N

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        
        ob = Solution()
        print(ob.bitMultiply(N))

# } Driver Code Ends
