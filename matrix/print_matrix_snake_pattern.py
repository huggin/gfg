# User function Template for python3


class Solution:
    # Function to return list of integers visited in snake pattern in matrix.
    def snakePattern(self, matrix):
        # code here
        n = len(matrix)
        j = 0
        ans = []
        for i in range(n):
            while j < n and j >= 0:
                ans.append(matrix[i][j])
                j += 1 if i % 2 == 0 else -1
            j += 1 if i % 2 == 1 else -1

        return ans


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
        ans = obj.snakePattern(matrix)
        for i in ans:
            print(i, end=" ")
        print()


# } Driver Code Ends
