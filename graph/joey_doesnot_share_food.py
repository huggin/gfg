# User function Template for python3
import sys

sys.setrecursionlimit(100000)


class Solution:
    def MaxmimumLength(self, nums):
        # Code here
        n = len(nums)
        MAX = 1000001

        g = [[] for _ in range(MAX)]
        for i in range(n):
            for j in range(6):
                g[nums[i][j]].append(i)

        was = [-1] * MAX
        pa = [-1] * MAX
        pb = [-1] * n
        self.iter = 0

        def dfs(v):
            was[v] = self.iter
            for w in g[v]:
                if pb[w] == -1:
                    pa[v] = w
                    pb[w] = v
                    return True

            for w in g[v]:
                if was[pb[w]] != self.iter:
                    if dfs(pb[w]):
                        pa[v] = w
                        pb[w] = v
                        return True
            return False

        ans = 0
        self.iter = 1
        r = 0

        for l in range(1, MAX):
            r = max(r, l - 1)
            while dfs(r + 1):
                r += 1
                self.iter += 1

            ans = max(ans, r - l + 1)
            if pa[l] != -1:
                pb[pa[l]] = -1
                pa[l] = -1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        nums = []
        for _ in range(n):
            nums.append(list(map(int, input().split())))
        obj = Solution()
        ans = obj.MaxmimumLength(nums)
        print(ans)


# } Driver Code Ends
