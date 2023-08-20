# User function Template for python3


class Solution:
    def Count(self, matrix):
        # Code here
        n = len(matrix)
        m = len(matrix[0])
        dx = [-1, -1, -1, 0, 0, 1, 1, 1]
        dy = [-1, 0, 1, -1, 1, -1, 0, 1]
        ans = 0
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    continue
                temp = 0
                for k in range(8):
                    ni = i + dx[k]
                    nj = j + dy[k]
                    if (
                        ni >= 0
                        and ni < n
                        and nj >= 0
                        and nj < m
                        and matrix[ni][nj] == 0
                    ):
                        temp += 1
                if temp != 0 and temp % 2 == 0:
                    ans += 1

        return ans


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
        ans = ob.Count(matrix)
        print(ans)

# } Driver Code Ends
