# User function Template for python3


class Solution:
    def minimumMoves(self, s):
        # Code here
        n = len(s)
        m = s.count("0")
        if 0 == m:
            return 0
        ans = 0
        i = 0
        while i < n:
            if s[i] == "0":
                j = i
                while j < n and s[j] == "0":
                    j += 1
                ans = max(ans, j - i)
                i = j + 1
            else:
                i += 1
        # print(ans)
        prefix = 0
        for i in range(n):
            if s[i] == "0":
                prefix += 1
            else:
                break
        suffix = 0
        for i in range(n - 1, -1, -1):
            if s[i] == "0":
                suffix += 1
            else:
                break
        ans = max(ans, prefix + suffix)
        return m - ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        s = input()
        ob = Solution()
        ans = ob.minimumMoves(s)
        print(ans)

# } Driver Code Ends
