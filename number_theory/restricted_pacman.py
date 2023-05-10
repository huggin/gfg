#User function Template for python3
import math
from collections import deque

class Solution: 
    def candies(self, m,n): 
        # Your code goes here 
        # ma = math.lcm(m, n) The python version is too low
        ma = m * n // math.gcd(n, m)
        marked = [0] * ma
        marked[0] = 1
        q = deque()
        q.append(0)
        while len(q) > 0:
            curr = q.popleft()
            if curr+m < ma and marked[curr+m] == 0:
                marked[curr+m] = 1
                q.append(curr+m)
            if curr+n < ma and marked[curr+n] == 0:
                marked[curr+n] = 1
                q.append(curr+n)
        
        return marked.count(0)

#{ 
 # Driver Code Starts
#Initial Template for Python 3
    
if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        m = arr[0]
        n = arr[1]
        obj = Solution()
        print(obj.candies(m,n)) 



# } Driver Code Ends
