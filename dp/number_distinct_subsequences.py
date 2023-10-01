# User function Template for python3


class Solution:
    def distinctSubsequences(self, S):
        # code here
        M = int(1e9 + 7)
        n = len(S)
        last_index = {}
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(n):
            if S[i] not in last_index:
                dp[i + 1] = dp[i] * 2 % M
            else:
                dp[i + 1] = (dp[i] * 2 - dp[last_index[S[i]]]) % M
            last_index[S[i]] = i

        return dp[n]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.distinctSubsequences(s)
        print(answer)

# } Driver Code Ends
