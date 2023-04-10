#User function Template for python3

import sys
from collections import deque
from typing import List
sys.setrecursionlimit(10**8)
class Solution:
    def countDistinctIslands(self, grid : List[List[int]]) -> int:
        # code here
        sign = set()
        n = len(grid)
        m = len(grid[0])
        
        marked = [[0 for _ in range(m)] for _ in range(n)]
        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]
        
        q = deque()
        for i in range(n):
            for j in range(m):
                if marked[i][j] == 0 and grid[i][j] == 1:
                    total = []
                    num = 0
                    q.append(i)
                    q.append(j)
                    marked[i][j] = 1
                    
                    while len(q) > 0:
                        x = q.popleft()
                        y = q.popleft()
                        total.append((x-i, y-j))
                        num += 1
                        for k in range(4):
                            nx = x + dx[k]
                            ny = y + dy[k]
                            if nx >= 0 and nx < n and ny >= 0 and ny < m and not marked[nx][ny] and grid[nx][ny]:
                                marked[nx][ny] = 1
                                q.append(nx)
                                q.append(ny)
    
                    s1 = 0
                    s2 = 0
                    for t in total:
                        s1 = s1 * 10 + t[0]
                        s2 = s2 * 10 + t[1]
                    sign.add((s1, s2))
        return len(sign)
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    for _ in range(int(input())):
        n,m=map(int,input().strip().split())
        grid=[]
        for i in range(n):
            grid.append([int(i) for i in input().strip().split()])
        obj=Solution()
        print(obj.countDistinctIslands(grid))
# } Driver Code Ends
