#User function Template for python3
class Solution:
	def findBitwiseOR(self, L,R):
		# code here
        while L < R:
            L |= L + 1
        return R | L
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		L,R = input().split(' ')
		L = int(L)
		R = int(R)
		ob = Solution()
		ans = ob.findBitwiseOR(L,R)
		print(ans)

# } Driver Code Ends
