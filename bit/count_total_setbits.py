#User function Template for python3

class Solution:
    def countBits(self, N):
        # code here
        ans = 0
        for i in range(20, 0, -1):
            if N & (1 << i):
                #print(i, N)
                ans += N % (1 << i) + 1 + (1 << i - 1) * i
                #print(ans)
                N &= (1<<i) - 1
                #print(N)
        if N % 2: 
            ans += 1
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        print(ob.countBits(N))
# } Driver Code Ends
