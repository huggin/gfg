#User function Template for python3
class Solution:
	def maxXor(self, a, n):
		# code here
        start = 0
        for i in range(18, -1, -1):
            ma = -1
            k = -1
            for j in range(start, n):
                if (a[j] & (1 << i)) and (ma == -1 or ma < a[j]):
                    ma = a[j]
                    k = j
            
            #print(i, k, ma)
            if k == -1:
                continue
            
            a[k], a[start] = a[start], a[k]
            start += 1
            for j in range(start, n):
                if a[j] & (1 << i): 
                    a[j] ^= ma
                
        ans = 0
        for j in range(n):
            #print(bin(a[j]))
            if ans < (ans ^ a[j]):
                ans ^= a[j]
        
        return ans
                

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		a = [int(x) for x in input().split()]
		ob = Solution()
		ans = ob.maxXor(a,n)
		print(ans)

# } Driver Code Ends
