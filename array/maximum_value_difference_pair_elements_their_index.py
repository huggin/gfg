#User function Template for python3

class Solution:
    def maxValue(self, arr, N):
        # code here 
        a, b, c, d = 0, 0, 100000, 100000
    
        for i in range(0, N):
            a = max(a, arr[i] + i)
            b = max(b, arr[i] - i)
            c = min(c, arr[i] + i)
            d = min(d, arr[i] - i)
    
        return max(a - c, b - d)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        arr=list(map(int,input().split()))
        
        ob = Solution()
        print(ob.maxValue(arr,N))
# } Driver Code Ends
