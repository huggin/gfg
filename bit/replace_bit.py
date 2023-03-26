#User function Template for python3

class Solution:
    def replaceBit(self, N, K):
        # code here
        k = -1
        for i in range(16, -1, -1):
            if N & (1 << i):
                k = i
                break
    
        if k - K + 1 >= 0: 
            N &= ~(1 << k - K + 1)
        return N

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n,k = input().strip().split(" ")
        n,k = int(n), int(k)
        ob = Solution()
        ans = ob.replaceBit(n,k)
        print(ans)
# } Driver Code Ends
