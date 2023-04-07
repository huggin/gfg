#User function Template for python3
from collections import deque

class Solution:
    def numberOfCells(self,n, m, r, c, u, d, mat):
        # code here
        if mat[r][c] == '#':
            return 0
            
        marked = [[0 for _ in range(m)] for _ in range(n)]
        marked[r][c] = 1

        q = deque()
        q.append(r)
        q.append(c)
        q.append(u)
        q.append(d)
        
        dx = [0, 0, -1, 1]
        dy = [-1, 1, 0, 0]
        
        ans = 0
        while len(q):
            x = q.popleft()
            y = q.popleft()
            cu = q.popleft()
            cd = q.popleft()
            ans += 1
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if not (nx >= 0 and nx < n and ny >= 0 and ny < m):
                    continue
                if mat[nx][ny] == '#' or marked[nx][ny] == 1:
                    continue
                if i == 2 and cu == 0:
                    continue
                if i == 3 and cd == 0:
                    continue
                marked[nx][ny] = 1
                q.append(nx)
                q.append(ny)
                if i == 2:
                    q.append(cu - 1)
                else:
                    q.append(cu)
                
                if i == 3:
                    q.append(cd - 1)
                else:
                    q.append(cd)
                
        return ans
                
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(int(input()))

    for tcs in range(t):

        n, m, r, c, u, d = [int(x) for x in input().split()]

        mat = []

        for i in range(n):
            matele = [x for x in input()]
            mat.append(matele)
        obj=Solution()
        print(obj.numberOfCells(n, m, r, c, u, d, mat))
# } Driver Code Ends
