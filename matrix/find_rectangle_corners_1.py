# User function Template for python3


class Solution:
    def ValidCorner(self, matrix):
        # Your code goes here
        m = len(matrix[0])
        n = len(matrix)
        for i in range(n):
            d = [0] * m
            for j in range(m):
                d[j] = matrix[i][j]
            for k in range(i + 1, n):
                cnt = 0
                for j in range(m):
                    if matrix[k][j] == 1 and d[j] == 1:
                        cnt += 1
                    if cnt == 2:
                        return True

        return False


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        r = int(input())
        c = int(input())
        line = input().strip().split()
        mat = [[0 for _ in range(c)] for _ in range(r)]
        for i in range(r):
            for j in range(c):
                mat[i][j] = int(line[i * c + j])
        ob = Solution()
        if ob.ValidCorner(mat):
            print("Yes")
        else:
            print("No")


# } Driver Code Ends
