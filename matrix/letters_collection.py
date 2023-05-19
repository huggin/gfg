# User function Template for python3


class Solution:
    def matrixSum(self, n, m, mat, q, queries):
        # code here
        ans = []
        for t, x, y in queries:
            temp = 0
            if t == 1:
                for i in range(-1, 2):
                    for j in range(-1, 2):
                        if i == 0 and j == 0:
                            continue
                        nx = x + i
                        ny = y + j
                        if nx < 0 or nx >= n or ny < 0 or ny >= m:
                            continue
                        temp += mat[nx][ny]
                ans.append(temp)
            else:
                for i in range(-2, 3):
                    for j in range(-2, 3):
                        if max(abs(i), abs(j)) != 2:
                            continue
                        nx = x + i
                        ny = y + j
                        if nx < 0 or nx >= n or ny < 0 or ny >= m:
                            continue
                        temp += mat[nx][ny]
                ans.append(temp)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = [int(x) for x in input().split()]
        mat = [[0] * m for x in range(n)]
        for i in range(n):
            arr = input().split()
            for j in range(m):
                mat[i][j] = int(arr[j])
        q = int(input())
        queries = [[0] * 3 for x in range(q)]
        for i in range(q):
            a = input().split()
            for j in range(3):
                queries[i][j] = int(a[j])

        ob = Solution()
        ans = ob.matrixSum(n, m, mat, q, queries)
        for i in range(q):
            print(ans[i])
# } Driver Code Ends
