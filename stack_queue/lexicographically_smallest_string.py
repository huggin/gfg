#User function Template for python3
class Solution:
    def power2(self, n):
        return (n & n - 1) == 0
        
    def lexicographicallySmallest (self, S, k):
        # code here 
        n = len(S)
        k = k // 2 if self.power2(n) else k * 2
        
        if k >= n:
            return "-1"
        
        s = []
        num = k
        for c in S:
            while len(s) > 0 and c < s[-1] and num > 0:
                s.pop()
                num -= 1
            s.append(c)
            
        while len(s) > n - k:
            s.pop()
            
        return ''.join(s)

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        S,k = input().split()
        k=int(k)
        
        ob = Solution()
        print(ob.lexicographicallySmallest(S, k))
# } Driver Code Ends
