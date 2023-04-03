#User function Template for python3
class Solution:
	def generateNextPalindrome(self, num, n) :
	    # code here
	    num2 = num[:]
        for i in range(n // 2):
            num[n-1-i] = num[i]
            
        if num2 < num:
            return num
        
        curr = n // 2
        while curr >= 0 and num[curr] == 9:
            num[curr] = 0
            num[n-1-curr] = 0
            curr -= 1
        
        if curr < 0:
            ans = [0] * (n+1)
            ans[0] = ans[-1] = 1
        else:
            num[curr] += 1
            num[n-1-curr] = num[curr]
            ans = num
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3



# Driver code 
if __name__ == "__main__": 		
    tc=int(input())
    while tc > 0:
        n=int(input())
        num=list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.generateNextPalindrome(num, n)
        for x in ans:
            print(x, end=" ")
        print()
        tc=tc-1
# } Driver Code Ends
