#User function Template for python3

class Solution:
	def total_count(self, n):
		# Code here
		cnt = 0
        for i in range(64):
            if (1 << i) <= n and ((1 << i) & n) == 0:
                cnt += 1
        
        return 1 << cnt


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution();
		ans = ob.total_count(n)
		print(ans)


# } Driver Code Ends
