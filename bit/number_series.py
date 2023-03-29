#User function Template for python3
class Solution:
    def findNth (ob, n):
        # code here
        ans = 0
        while n:
            if n&1:
                return ans
            else:
                ans += 1
                n >>= 1
        
        return -1

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = input()
        n = int(n)
        ob = Solution()
        print(ob.findNth(n))
# } Driver Code Ends
