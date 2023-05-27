# User function Template for python3


class Solution:
    def compress(self, s):
        # Your code goes here
        n = len(s)
        hash = [0] * n
        p = 31
        M = int(1e9 + 7)
        ppow = [1] * n
        hash[0] = ord(s[0]) - ord("a") + 1

        for i in range(1, n):
            ppow[i] = ppow[i - 1] * p % M
            hash[i] = (hash[i - 1] + (ord(s[i]) - ord("a") + 1) * ppow[i]) % M

        ans = ""
        i = n - 1
        while i >= 0:
            if (
                i % 2
                and hash[i // 2] * ppow[i // 2 + 1] % M
                == (hash[i] - hash[i // 2] + M) % M
            ):
                ans += "*"
                i //= 2
            else:
                ans += s[i]
                i -= 1

        return ans[::-1]


# {
# Driver Code Starts
# Initial Template for Python 3


t = int(input())
for _ in range(0, t):
    s = input()
    obj = Solution()
    ans = obj.compress(s)
    print(ans)

# } Driver Code Ends
