# User function Template for python3


class Solution:
    # Function to return sum of upper and lower triangles of a matrix.
    def sumTriangles(self, matrix, n):
        # code here
        a, b = 0, 0
        for i in range(n):
            for j in range(n):
                if i > j:
                    b += matrix[i][j]
                elif i < j:
                    a += matrix[i][j]
                else:
                    a += matrix[i][j]
                    b += matrix[i][j]

        return [a, b]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        matrix = [[0 for j in range(n)] for i in range(n)]
        line1 = [int(x) for x in input().strip().split()]

        k = 0
        for i in range(n):
            for j in range(n):
                matrix[i][j] = line1[k]
                k += 1
        obj = Solution()
        ans = obj.sumTriangles(matrix, n)
        for i in ans:
            print(i, end=" ")
        print()
# } Driver Code Ends
