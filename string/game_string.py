#User function Template for python3
from collections import Counter
import heapq

class Solution:
    def minValue(self, s, k):
        # code here
        c = Counter(s)
        pq = []
        for _, v in c.items():
            heapq.heappush(pq, -v)

        for _ in range(k):
            heapq.heapreplace(pq, pq[0]+1)
            
        return sum(a * a for a in pq)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        k = int(input())
        
        ob = Solution()
        print(ob.minValue(s, k))
# } Driver Code Ends
