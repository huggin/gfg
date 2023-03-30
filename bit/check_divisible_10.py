#User function Template for python3

class Solution:
    def isDivisibleBy10(self,bin):
        #code here
        n = int(bin, 2)
        return 1 if n % 10 == 0 else 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        bin=input()
        ob=Solution()
        print(ob.isDivisibleBy10(bin))
# } Driver Code Ends
