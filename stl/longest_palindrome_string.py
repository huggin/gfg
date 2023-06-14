# User function Template for python3


class Solution:
    def manacher_odd(self, s):
        n = len(s)
        s = "$" + s + "^"
        p = [0] * (n + 2)
        l, r = 1, 1
        for i in range(1, n + 1):
            p[i] = max(0, min(r - i, p[l + (r - i)]))
            while s[i - p[i]] == s[i + p[i]]:
                p[i] += 1
            if i + p[i] > r:
                l, r = i - p[i], i + p[i]
        return p[1 : n + 1]

    def longestPalin(self, S):
        # code here
        s = "#" + "#".join(c for c in S) + "#"
        p = self.manacher_odd(s)
        ma = -1
        idx = -1
        for i in range(len(p)):
            if p[i] > ma:
                ma = p[i]
                idx = i

        ans = s[idx - ma + 1 : idx + ma - 1]
        return "".join(ans.split("#"))


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        S = input()

        ob = Solution()

        ans = ob.longestPalin(S)

        print(ans)
# } Driver Code Ends
