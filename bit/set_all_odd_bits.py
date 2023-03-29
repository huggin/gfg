#User function Template for python3

class Solution:
    def setAllOddBits (ob, n):
        # code here 
        for i in range(0, 32, 2):
            if (1 << i) <= n:
                n |= (1 << i)

        return n


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = int(input())
        
        ob = Solution()
        print(ob.setAllOddBits(n))
# } Driver Code Ends
