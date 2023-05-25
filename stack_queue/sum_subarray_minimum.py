# User function Template for python3


class Solution:
    def solve(self, a, n, cmp, reverse=False):
        ans = [-1] * n
        r = reversed(range(n)) if reverse else range(n)
        stack = []
        for i in r:
            while len(stack) > 0 and cmp(a[stack[-1]], a[i]):
                stack.pop()

            if len(stack) == 0:
                ans[i] = n if reverse else -1
            else:
                ans[i] = stack[-1]
            stack.append(i)
        return ans

    def sumSubarrayMins(self, n, arr):
        # Code here
        M = int(1e9 + 7)
        left = self.solve(arr, n, lambda x, y: x > y)
        right = self.solve(arr, n, lambda x, y: x >= y, True)

        ans = 0
        for i in range(n):
            ans = (ans + (i - left[i]) * (right[i] - i) * arr[i]) % M
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
        res = ob.sumSubarrayMins(N, arr)
        print(res)
# } Driver Code Ends
