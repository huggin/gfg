#User function Template for python3

class Solution:
	def find_and(self, l, r):
		# Code here
        while r > l:
            r &= r-1
        return r & l


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		l, r = input().split()
		l = int(l)
		r = int(r)
		ob = Solution();
		ans = ob.find_and(l, r)
		print(ans)

# } Driver Code Ends
