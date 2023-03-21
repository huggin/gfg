#User function Template for python3

class Solution:
    def divide(self, a, b):
        #code here
        if a == 0:
            return 0
        sign = 1 if a > 0 else -1
        sign = sign * (1 if b > 0 else -1)
        a = abs(a)
        b = abs(b)
        ans = 0
        for i in range(31, -1, -1):
            if (b << i) <= a:
                ans += 1 << i
                a -= b << i
        
        return sign * ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        inp = list(map(int,input().split())) 
        
        a=inp[0]
        b=inp[1]
        
        ob=Solution()
        
        print(ob.divide(a,b))
        
# } Driver Code Ends
