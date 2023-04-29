# User function Template for python3
class Solution:
    def rotateMatrix(self, arr, n):
        # code here
        for i in range(n // 2):
            for j in range(i, n - 1 - i):
                temp = arr[i][j]
                arr[i][j] = arr[j][n - 1 - i]
                arr[j][n - 1 - i] = arr[n - 1 - i][n - 1 - j]
                arr[n - 1 - i][n - 1 - j] = arr[n - 1 - j][i]
                arr[n - 1 - j][i] = temp

        return arr


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        inputLine = list(map(int, input().strip().split()))
        arr = [[0 for j in range(n)] for i in range(n)]
        for i in range(n):
            for j in range(n):
                arr[i][j] = inputLine[i * n + j]
        ob = Solution()
        ob.rotateMatrix(arr, n)
        for i in range(n):
            for j in range(n):
                print(arr[i][j], end=" ")
        print()
        tc -= 1

# } Driver Code Ends
