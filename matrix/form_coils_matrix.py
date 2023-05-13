# User function Template for python3


class Solution:
    def formCoils(self, n):
        # code here
        ans = [[], []]
        curr = [[4 * n - 1, 4 * n - 1], [0, 0]]
        d0 = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        d1 = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        m = [[0 for _ in range(4 * n)] for _ in range(4 * n)]
        start = 1
        for i in range(4 * n):
            for j in range(4 * n):
                m[i][j] = start
                start += 1

        marked = [[0 for _ in range(4 * n)] for _ in range(4 * n)]
        k = 0
        while len(ans[0]) < 8 * n * n:
            marked[curr[0][0]][curr[0][1]] = 1
            ans[0].append(m[curr[0][0]][curr[0][1]])
            marked[curr[1][0]][curr[1][1]] = 1
            ans[1].append(m[curr[1][0]][curr[1][1]])
            if not (
                curr[0][0] + d0[k][0] < 4 * n
                and curr[0][0] + d0[k][0] >= 0
                and curr[0][1] + d0[k][1] >= 0
                and curr[0][1] + d0[k][0] < 4 * n
                and marked[curr[0][0] + d0[k][0]][curr[0][1] + d0[k][1]] == 0
            ):
                k = (k + 1) % 4

            curr[0][0] += d0[k][0]
            curr[0][1] += d0[k][1]
            curr[1][0] += d1[k][0]
            curr[1][1] += d1[k][1]

        ans[0].reverse()
        ans[1].reverse()
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        ptr = ob.formCoils(n)

        for i in range(2):
            print(*ptr[i])
# } Driver Code Ends
