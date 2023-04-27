#User function Template for python3


from typing import List
from collections import deque

class Solution:
    def chefAndWells(self, n : int, m : int, c : List[List[str]]) -> List[List[int]]:
        ans = [[-1 for _ in range(m)] for _ in range(n)]
        marked = [[0 for _ in range(m)] for _ in range(n)]

        q = deque()
        for i in range(n):
            for j in range(m):
                if c[i][j] == 'W':
                    ans[i][j] = 0
                    q.append((i, j))
                    marked[i][j] = 1
        
        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]
        
        while len(q) > 0:
            x, y = q.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if not (nx >= 0 and nx < n and ny >= 0 and ny < m):
                    continue
                if marked[nx][ny] == 1 or c[nx][ny] == 'N':
                    continue
                ans[nx][ny] = 2 + ans[x][y]
                marked[nx][ny] = 1
                q.append((nx, ny))
        
        for i in range(n):
            for j in range(m):
                if c[i][j] == 'N' or c[i][j] == '.':
                    ans[i][j] = 0
        
        return ans
                
                
            
                    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

from typing import List

class StringMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([i for i in input().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()



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
        
        n,m= map(int,input().split())
    
        
        
        c=StringMatrix().Input(n, m)
        
        obj = Solution()
        res = obj.chefAndWells(n, m, c)
        
        for el in res:
            for c in el:
                print(c, end=" ")
            print()

# } Driver Code Ends
