# User function Template for python3


class Solution:
    def computeBeforeMatrix(self, N, M, after):
        # Code here
        ans = [[0 for _ in range(M)] for _ in range(N)]
        ans[0][0] = after[0][0]
        for i in range(1, M):
            ans[0][i] = after[0][i] - after[0][i - 1]

        for i in range(1, N):
            ans[i][0] = after[i][0] - after[i - 1][0]

        for i in range(1, N):
            for j in range(1, M):
                ans[i][j] = (
                    after[i][j]
                    - after[i - 1][j]
                    - after[i][j - 1]
                    + after[i - 1][j - 1]
                )
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    while T > 0:
        N, M = [int(i) for i in input().split()]
        after = []
        for j in range(N):
            after.append([int(i) for i in input().split()])
        ob = Solution()
        before = ob.computeBeforeMatrix(N, M, after)
        for i in range(len(before)):
            for j in range(len(before[i])):
                print(before[i][j], end=" ")
            print()

        T -= 1
# } Driver Code Ends
