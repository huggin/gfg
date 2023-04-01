#User function Template for python3
from collections import deque

class Solution:
    def knightInGeekland(self, arr, start):
        n = len(arr)
        m = len(arr[0])
        
        marked = [[0 for _ in range(m)] for _ in range(n)]
        marked[start[0]][start[1]] = 1
        
        points = []
        q = deque()
        q.append(start[0])
        q.append(start[1])
        
        dx = [-2, -2, -1, -1, 1, 1, 2, 2]
        dy = [-1, 1, -2, 2, -2, 2, -1, 1]
        while len(q) > 0:
            sz = len(q) // 2
            cp = 0
            for _ in range(sz):
                x = q.popleft()
                y = q.popleft()
                cp += arr[x][y]
                
                for k in range(8):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if nx >= 0 and nx < n and ny >= 0 and ny < m and not marked[nx][ny]:
                        q.append(nx)
                        q.append(ny)
                        marked[nx][ny] = 1
            
            points.append(cp)
        
        ans = -1
        ma = 0
        sz = len(points)
        for i in range(sz - 1, -1, -1):
            if i + points[i] < len(points):
                points[i] += points[i+points[i]]
            
            if points[i] >= ma:
                ma = points[i]
                ans = i
        
        return ans
        
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    test_cases = int(input())
    for _ in range (test_cases):
        n,m = map(int, input().split())
        starting_x, starting_y = map(int, input().split())
        orignal_array = []

        for i in range(n):
            l = list(map(int, input().split()))
            orignal_array.append(l)

        res = Solution().knightInGeekland(orignal_array, [starting_x, starting_y])
        print(res)
# } Driver Code Ends
