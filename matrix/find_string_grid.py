# User function Template for python3


class Solution:
    def searchWord(self, grid, word):
        # Code here
        n = len(grid)
        m = len(grid[0])
        dx = [-1, -1, -1, 0, 0, 1, 1, 1]
        dy = [-1, 0, 1, -1, 1, -1, 0, 1]
        ans = []

        for i in range(n):
            for j in range(m):
                if grid[i][j] != word[0]:
                    continue
                wn = len(word)
                found = False
                for k in range(8):
                    if (
                        i + (wn - 1) * dx[k] >= 0
                        and i + (wn - 1) * dx[k] < n
                        and j + (wn - 1) * dy[k] >= 0
                        and j + (wn - 1) * dy[k] < m
                    ):
                        idx = 0
                        while idx < wn:
                            ni = i + idx * dx[k]
                            nj = j + idx * dy[k]
                            if word[idx] != grid[ni][nj]:
                                break
                            idx += 1
                        if idx == wn:
                            found = True
                            break

                if found:
                    ans.append((i, j))

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n)
        m = int(m)
        grid = []
        for _ in range(n):
            cur = input()
            temp = []
            for __ in cur:
                temp.append(__)
            grid.append(temp)
        word = input()
        obj = Solution()
        ans = obj.searchWord(grid, word)
        for _ in ans:
            for __ in _:
                print(__, end=" ")
            print()
        if len(ans) == 0:
            print(-1)

# } Driver Code Ends
