# User function Template for python3


class Solution:
    def printDiamond(self, N):
        # Code here
        pattern = []
        for i in range(1, N + 1):
            mid = " ".join("*" for i in range(i))
            space = " " * ((2 * N - 1 - len(mid)) // 2)
            pattern.append(space + mid)

        for i in pattern:
            print(i)

        for i in reversed(pattern):
            print(i)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ob.printDiamond(N)
# } Driver Code Ends
