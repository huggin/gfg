# User function Template for python3


# You are required to complete this fucntion
# Function should return an integer
class Solution:
    def findK(self, a, n, m, k):
        # Your code goes here
        x, y = 0, 0
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]

        dr = 0
        min_c, max_c = 0, m - 1
        min_r, max_r = 0, n - 1
        while k > 0:
            k -= 1
            if k == 0:
                return a[x][y]
            if x + dx[dr] > max_r:
                dr = (dr + 1) % 4
                max_c -= 1
            elif x + dx[dr] < min_r:
                dr = (dr + 1) % 4
                min_c += 1
            elif y + dy[dr] > max_c:
                dr = (dr + 1) % 4
                min_r += 1
            elif y + dy[dr] < min_c:
                dr = (dr + 1) % 4
                max_r -= 1

            x += dx[dr]
            y += dy[dr]

        return -1


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        matrix = [[0 for i in range(n[1])] for j in range(n[0])]
        c = 0
        for i in range(n[0]):
            for j in range(n[1]):
                matrix[i][j] = arr[c]
                c += 1
        obj = Solution()
        print(obj.findK(matrix, n[0], n[1], n[2]))

# } Driver Code Ends
