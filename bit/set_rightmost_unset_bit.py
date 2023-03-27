#User function Template for python3
class Solution:
	def setBit(self, N):
		# code here
        k = 0
        while (1<<k) <= N:
            if N & (1<<k)== 0:
                N |= (1<<k)
                return N
            k += 1
        
        return N

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())

		ob = Solution()
		ans = ob.setBit(N)
		print(ans)




# } Driver Code Ends
