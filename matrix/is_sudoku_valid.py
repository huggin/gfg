#User function Template for python3
class Solution:
    def isValid(self, mat):
        # code here
        for i in range(9):
            c = [0] * 10
            for j in range(9):
                if mat[i][j] == 0:
                    continue
                c[mat[i][j]] += 1
                if c[mat[i][j]] > 1:
                    return 0
            
        for j in range(9):
            c = [0] * 10
            for i in range(9):
                if mat[i][j] == 0:
                    continue
                c[mat[i][j]] += 1
                if c[mat[i][j]] > 1:
                    return 0
                        
        for k in range(9):
            x = k // 3
            y = k % 3
            c = [0] * 10
            for i in range(3*x, 3*x+3):
                for j in range(3*y, 3*y+3):
                    if mat[i][j] == 0:
                        continue
                    c[mat[i][j]] += 1
                    if c[mat[i][j]] > 1:
                        return 0
        
        return 1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = input().split()
        mat = [[0]*9 for x in range(9)]
        for i in range(81):
            mat[i//9][i%9] = int(arr[i])
        
        ob = Solution()
        print(ob.isValid(mat))
# } Driver Code Ends
