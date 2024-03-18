# User function Template for python3


class Solution:
    def FactDigit(self, N):
        # Code here
        dp = [1] * 10
        for i in range(1, 10):
            dp[i] = dp[i - 1] * i

        ans = []
        j = 9
        while N > 0:
            while N >= dp[j]:
                ans.append(j)
                N -= dp[j]
            j -= 1

        return "".join(str(c) for c in reversed(ans))


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        N = int(input())
        ob = Solution()
        ans = ob.FactDigit(N)
        for _ in ans:
            print(_, end="")
        print()
# } Driver Code Ends
