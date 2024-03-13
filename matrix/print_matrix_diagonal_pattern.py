# Your task is to complete this function


class Solution:
    def matrixDiagonally(self, mat):
        # code here
        ans = []
        n = len(mat)
        for k in range(2 * n - 1):
            if k < n:
                if k % 2 == 0:
                    for j in reversed(range(k, -1, -1)):
                        ans.append(mat[k - j][j])
                else:
                    for j in range(k, -1, -1):
                        ans.append(mat[k - j][j])
            else:
                if k % 2 == 0:
                    for j in reversed(range(n - 1, k - n, -1)):
                        ans.append(mat[k - j][j])
                else:
                    for j in range(n - 1, k - n, -1):
                        ans.append(mat[k - j][j])
        return ans


# {
# Driver Code Starts
# Driver Program
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        matrix = [[0 for i in range(n[0])] for j in range(n[0])]
        k = 0
        for i in range(n[0]):
            for j in range(n[0]):
                matrix[i][j] = arr[k]
                k += 1
        a = Solution().matrixDiagonally(matrix)
        for x in a:
            print(x, end=" ")
        print("")
# Contributed by: Harshit Sidhwa
# } Driver Code Ends
