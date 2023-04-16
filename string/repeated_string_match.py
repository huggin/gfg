#User function Template for python3
import math

class Solution:
    def repeatedStringMatch(self, A, B):
        # code here
        n = math.ceil(len(B) / len(A))
        a = A * n

        for i in range(n+1):
            if B in a:
                return n + i
            a = a + A
        
        return -1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t=int(input())
    for _ in range(t):
        A=input().strip()
        B=input().strip()
        obj = Solution()
        print(obj.repeatedStringMatch(A,B))
# } Driver Code Ends
