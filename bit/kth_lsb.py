#User function Template for python3
class Solution:
	def KthLSB(self, n, k):
		# code here
        return 1 if n & (1<<k-1) else 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n,k = input().split(' ')
		n = int(n)
		k = int(k)
		ob = Solution()
		ans = ob.KthLSB(n,k)
		print(ans)

# } Driver Code Ends
