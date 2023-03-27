#User function Template for python3
class Solution:
	def getXor(self, A, N):
		# code here
        ans = 0
        for i in range(N):
            ans ^= A[i]
            
        for i in range(N):
            A[i] = ans ^ A[i];
        
        return A;

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        N = int(input())
        A = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.getXor(A, N)
        for x in ans:
            print(x,end=" ")
        print("")


# } Driver Code Ends
