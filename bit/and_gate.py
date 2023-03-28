#User function Template for python3
class Solution:
    def andGate (self, arr, N):
        # code here
        return 0 if 0 in arr else 1

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        arr = input().split(' ')
        for itr in range(N):
            arr[itr] = int(arr[itr])
       
        ob = Solution()
        print(ob.andGate(arr,N))
# } Driver Code Ends
