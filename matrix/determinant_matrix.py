# User function Template for python3


class Solution:
    # Function for finding determinant of matrix.
    def determinantOfMatrix(self, a, n):
        # code here
        EPS = 1e-9
        n = len(a)
        det = 1
        for i in range(n):
            k = i
            for j in range(i + 1, n):
                if abs(a[j][i]) > abs(a[k][i]):
                    k = j
            if abs(a[k][i]) < EPS:
                det = 0
                break

            a[i], a[k] = a[k], a[i]
            if i != k:
                det = -det

            det *= a[i][i]
            for j in range(i + 1, n):
                a[i][j] /= a[i][i]

            for j in range(n):
                if j != i and abs(a[j][i]) > EPS:
                    for k in range(i + 1, n):
                        a[j][k] -= a[i][k] * a[j][i]

        return int(det + 0.5) if det > 0 else int(det - 0.5)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix = []
        for i in range(n):
            row = []
            for j in range(n):
                row.append(values[k])
                k += 1
            matrix.append(row)
        obj = Solution()
        print(obj.determinantOfMatrix(matrix, n))
# } Driver Code Ends
