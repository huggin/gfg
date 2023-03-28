#User function Template for python3


class Solution:
    def xorGate (self, arr, N):
        #code here
        ans = 0
        for i in range(N):
            ans ^= arr[i]
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        arr = [int(i) for i in input().split()]
       

        ob = Solution()
        print(ob.xorGate(arr,N))
# } Driver Code Ends
