#User function Template for python3
import math

class Solution:
	def superPrimes(self, n):
		# code here
        ok = [1] * (n+1)
        ok[0] = ok[1] = 0
        for i in range(2, int(math.sqrt(n+1)) + 1):
            if ok[i]:
                for j in range(i*i, n+1, i):
                    ok[j] = 0
        ans = 0
        for i in range(5, n+1):
            if ok[i] and ok[i-2]:
                ans += 1
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution()
		ans = ob.superPrimes(n)
		print(ans)

# } Driver Code Ends
