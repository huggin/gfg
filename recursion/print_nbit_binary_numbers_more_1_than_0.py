# User function Template for python3
class Solution:
    def solve(self, k, N, one, curr):
        if k == N:
            self.ans.append("".join(curr))
            return

        curr.append("1")
        self.solve(k + 1, N, one + 1, curr)
        curr.pop()

        if one > 0:
            curr.append("0")
            self.solve(k + 1, N, one - 1, curr)
            curr.pop()

    def NBitBinary(self, N):
        # code here
        self.ans = []
        self.solve(0, N, 0, [])

        return self.ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        answer = ob.NBitBinary(n)
        for value in answer:
            print(value, end=" ")
        print()


# } Driver Code Ends
