from typing import List
import bisect

class Solution:
    def maxCoins(self, n : int, ranges : List[List[int]]) -> int:
        # code here
        ranges.sort(key = lambda x : (x[1], x[0], x[2]))
        curr = [(0, 0)]
        ans = 0
        for i in range(n):
            idx = bisect.bisect_left(curr, (ranges[i][0], int(1e7))) - 1
            ans = max(ans, ranges[i][2] + curr[idx][1])
            if ranges[i][2] >= curr[-1][1]:
                curr.append((ranges[i][1], ranges[i][2]))
        
        return ans
            
        


#{ 
 # Driver Code Starts
class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        ranges=IntMatrix().Input(n, 3)
        
        obj = Solution()
        res = obj.maxCoins(n, ranges)
        
        print(res)
        

# } Driver Code Ends
