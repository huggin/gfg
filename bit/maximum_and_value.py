#User function Template for python3
class Solution:

	def maxAND (self, arr,  n) :
		# Complete the function
		ans = 0
        for i in range(18, -1, -1):
            temp = []
            for a in arr:
                if a & (1 << i):
                    temp.append(a)
            
            if len(temp) == 2:
                return temp[0] & temp[1]
            elif len(temp) > 2:
                arr = temp
                ans += (1 << i)
        
        return ans
                

#{ 
 # Driver Code Starts
#Initial Template for Python 3


   
for _ in range(0,int(input())):
    
    n = int(input())
    arr = list(map(int,input().strip().split()))
    ob = Solution()
    print(ob.maxAND(arr, n))
# } Driver Code Ends
