# User function Template for python3


class Solution:
    def transpose(self, matrix, n):
        # Write Your code here
        matrix[:] = list(map(list, zip(*matrix)))


# {
# Driver Code Starts

# Initial Template for Python 3

for _ in range(int(input())):
    n = int(input())
    matrix = [list(map(int, input().split())) for _ in range(n)]

    ob = Solution()
    ob.transpose(matrix, n)

    for row in matrix:
        print(*row)

# } Driver Code Ends
