#{ 
 # Driver Code Starts
#Initial Template for Python 3
from collections import Counter

class Solution:
    def countSubstring(self, S): 
        #code here
        n = len(S)
        d = Counter()
        d[0] = 1
        cnt = 0
        ans = 0
        for c in S:
            if c.isupper():
                cnt += 1
            else:
                cnt -= 1
            ans += d[cnt];
            d[cnt] += 1
        return ans

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        S = input()
        ob = Solution()
        ans = ob.countSubstring(S)
        print(ans)

# } Driver Code Ends
