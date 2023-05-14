# User function Template for python3


class Solution:
    def solve(self, k, n, curr):
        if k == n:
            num = 0
            for i in range(len(curr)):
                num = num * 2 + int(curr[i])
            if num != 0:
                self.ans.append(num)
            return

        curr.append("0")
        self.solve(k + 1, n, curr)
        curr.pop()
        if len(curr) == 0 or curr[-1] == "0":
            curr.append("1")
            self.solve(k + 1, n, curr)
            curr.pop()

    def numberWithNoConsecutiveOnes(self, n):
        # Code here
        self.ans = []
        self.solve(0, n, [])
        return self.ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.numberWithNoConsecutiveOnes(n)
        for _ in ans:
            print(_, end=" ")
        print()
# } Driver Code Ends
