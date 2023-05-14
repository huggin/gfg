# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def solve(self, k, n, curr):
        if k == n:
            self.ans.append("".join(curr))
            return

        curr.append("0")
        self.solve(k + 1, n, curr)
        curr.pop()
        if len(curr) == 0 or curr[-1] == "0":
            curr.append("1")
            self.solve(k + 1, n, curr)
            curr.pop()

    def generateBinaryStrings(self, n):
        # Code here
        self.ans = []
        self.solve(0, n, [])
        return self.ans


# {
# Driver Code Starts.
from sys import stdout

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        res = ob.generateBinaryStrings(N)
        for binaryString in res:
            print(binaryString, end=" ")
        print()
# } Driver Code Ends
