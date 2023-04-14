#User function Template for python3
class Solution:

	def maxIndexDiff(self,arr,n):
		#code here
        LMin = [0] * n
        RMax = [0] * n
    
        LMin[0] = arr[0]
        for i in range(1, n):
            LMin[i] = min(arr[i], LMin[i-1])
        
        RMax[n-1] = arr[n-1]
        for j in range(n-2, -1, -1):
            RMax[j] = max(arr[j], RMax[j+1])
        
        i, j, ans = 0, 0, -1
        while i < n and j < n:
            if LMin[i] <= RMax[j]:
                ans = max(ans, j-i)
                j += 1
            else:
                i += 1
            
        return ans


#{ 
 # Driver Code Starts
if __name__ == "__main__":
	t = int(input())
	while(t>0):
		num = int(input())
		arr = [int(x) for x in input().strip().split()]
		ob = Solution()
		print(ob.maxIndexDiff(arr,num))
		t-=1
# } Driver Code Ends
