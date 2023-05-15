# User function Template for python3


class Solution:
    def solve(self, c, k, t, curr):
        if t == 0:
            self.ans.append(curr.copy())
            return
        if t < 0 or k == n:
            return

        if t < c[k]:
            return
        curr.append(c[k])
        self.solve(c, k + 1, t - c[k], curr)
        curr.pop()
        j = k + 1
        while j < n and c[j] == c[k]:
            j += 1
        self.solve(c, j, t, curr)

    def combinationSum2(self, candidates, target):
        # Code here
        candidates.sort()
        self.ans = []
        self.solve(candidates, 0, target, [])
        return self.ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, target = list(map(int, input().split()))
        candidates = list(map(int, input().split()))
        ob = Solution()
        res = ob.combinationSum2(candidates, target)
        res.sort()
        print("[ ", end="")
        for subset in res:
            print("[ ", end="")
            for val in subset:
                print(val, end=" ")
            print("]", end="")
        print(" ]")
# } Driver Code Ends
