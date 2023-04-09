#User function Template for python3
class Solution:
	def checkTriplet(self,arr, n):
    	# code here
        a = list(set(arr))
        a.sort()
        for i in range(2, len(a)):
            j = 0
            k = i - 1
            while j < k:
                t = a[j] * a[j] + a[k] * a[k]
                if t == a[i] * a[i]:
                    return True
                elif t > a[i] * a[i]:
                    k -= 1
                else:
                    j += 1
        
        return False
#{ 
 # Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.checkTriplet(arr, n)
        if ans:
            print("Yes")
        else:
            print("No")
        tc -= 1

# } Driver Code Ends
