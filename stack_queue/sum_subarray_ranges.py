# User function Template for python3


class Solution:
    def solve(self, a, n, cmp, reverse=False):
        ans = [-1] * n
        stack = []
        r = reversed(range(n)) if reverse else range(n)
        for i in r:
            while len(stack) > 0 and cmp(a[stack[-1]], a[i]):
                stack.pop()
            if len(stack) == 0:
                ans[i] = n if reverse else -1
            else:
                ans[i] = stack[-1]
            stack.append(i)

        return ans

    def subarrayRanges(self, N, arr):
        # Code here
        left_min = self.solve(arr, N, lambda x, y: x > y)
        right_min = self.solve(arr, N, lambda x, y: x >= y, reverse=True)
        left_max = self.solve(arr, N, lambda x, y: x < y)
        right_max = self.solve(arr, N, lambda x, y: x <= y, reverse=True)

        ans = 0
        for i in range(N):
            ans -= (i - left_min[i]) * (right_min[i] - i) * arr[i]
            ans += (i - left_max[i]) * (right_max[i] - i) * arr[i]
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.subarrayRanges(N, arr)
        print(res)
# } Driver Code Ends
