# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def betterString(self, str1, str2):
        # Code here
        def f(s):
            last_index = [-1] * 26
            n = len(s)
            dp = [0] * (n + 1)
            dp[0] = 1
            for i in range(n):
                dp[i + 1] = dp[i] * 2
                j = ord(s[i]) - ord("a")
                if last_index[j] != -1:
                    dp[i + 1] -= dp[last_index[j]]
                last_index[j] = i

            return dp[n]

        if f(str1) >= f(str2):
            return str1
        return str2


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        str1 = input()
        str2 = input()
        ob = Solution()
        res = ob.betterString(str1, str2)
        print(res)
# } Driver Code Ends
