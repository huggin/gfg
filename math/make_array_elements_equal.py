#User function Template for python3

class Solution:
    def minOperations(self, N):
        # Code here
        if N == 1:
            return 0

        return N * N // 4

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    
    T = int(input())
    while T > 0: 
        N =int(input())
        ob = Solution()
        print(ob.minOperations(N))
        
        T -= 1

# } Driver Code Ends
