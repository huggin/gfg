#User function Template for python3
def solve(arr, k, curr, ans):
    if k == len(arr):
        ans.append(sum(curr))
        return
    solve(arr, k+1, curr, ans)
    curr.append(arr[k])
    solve(arr, k+1, curr, ans)
    curr.pop()
    
class Solution:
	def subsetSums(self, arr, N):
		# code here
        ans = []
        curr = []
        solve(arr, 0, curr, ans)
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        N = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.subsetSums(arr, N)
        ans.sort()
        for x in ans:
            print(x,end=" ")
        print("")

# } Driver Code Ends
