#User function Template for python3

class Solution:
	def xor_play(self, n):
		# code here
		if n == 1:
		    return [0]
        result = [1]
        i = 2
        while i*i <= n:
            if n % i == 0:
                result.append(i)
                if i != n//i:
                    result.append(n//i)
            i += 1
        
        result.sort()
      
        xor_result = 0
        for d in result:
            xor_result ^= d
        
        result.append(xor_result)
        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution();
		ans = ob.xor_play(n)
		for i in range(len(ans) - 1):
			print(ans[i], end = " ")
		print()
		print(ans[-1])

# } Driver Code Ends
