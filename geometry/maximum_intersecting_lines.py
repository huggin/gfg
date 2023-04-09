#User function Template for python3
import heapq

class Solution: 
    def maxIntersections(self, lines, N):
        # Code here
        lines.sort()
        
        ans = 0
        pq = []
        for i in range(N):
            if len(pq) > 0 and pq[0] < lines[i][0]:
                heapq.heappop(pq)
            heapq.heappush(pq, lines[i][1])
            ans = max(ans, len(pq))
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    
    T = int(input())
    while T > 0: 
        N = int(input())
        lines=[[] for j in range(N)]
        for j in range(2):
            prr = [int(i) for i in input().split()] 
            for i in range(N): 
                lines[i].append(prr[i])
            
    
        ob = Solution()
        print(ob.maxIntersections(lines, N))
        
        T -= 1

# } Driver Code Ends
