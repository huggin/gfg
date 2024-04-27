# User function Template for python3


class Solution:
    def FindExitPoint(self, n, m, matrix):
        # Code here
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        k, i, j = 0, 0, 0
        while True:
            if matrix[i][j] == 1:
                k = (k + 1) % 4
                matrix[i][j] = 0
            ni = i + dx[k]
            nj = j + dy[k]
            if ni >= 0 and ni < n and nj >= 0 and nj < m:
                i, j = ni, nj
            else:
                break
        return (i, j)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n)
        m = int(m)
        matrix = []
        for _ in range(n):
            matrix.append(list(map(int, input().split())))
        ob = Solution()
        ans = ob.FindExitPoint(n, m, matrix)
        for _ in ans:
            print(_, end=" ")
        print()

# } Driver Code Ends
