# User function Template for python3


class Solution:
    def solve(self, k, n, start, target, curr):
        if k == n and target == 0:
            self.ans.append(curr.copy())
            return
        if target < 0 or k > n:
            return

        for i in range(start, 10):
            curr.append(i)
            self.solve(k + 1, n, i + 1, target - i, curr)
            curr.pop()

    def combinationSum(self, K, target):
        # Code here
        self.ans = []
        self.solve(0, K, 1, target, [])
        return self.ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        K, N = list(map(int, input().split()))
        ob = Solution()
        ans = ob.combinationSum(K, N)
        for combination in ans:
            for val in combination:
                print(val, end=" ")
            print()
# } Driver Code Ends
