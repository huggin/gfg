# User function Template for python3


class Solution:
    def z_function(self, s):
        n = len(s)
        z = [0] * n
        z[0] = n
        l, r = 0, 0
        for i in range(1, n):
            if i < r:
                z[i] = min(r - i, z[i - l])
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
            if i + z[i] > r:
                r = i + z[i]
                l = i
        return z

    def maxFrequency(self, S):
        # code here
        z = self.z_function(S)
        ans = 0
        n = len(S)
        for i in range(n - 1, -1, -1):
            if z[i] == n - i:
                suffix = S[-z[i]:]
                start = 0
                while True:
                    pos = S.find(suffix, start)
                    if pos == -1:
                        return ans
                    ans += 1
                    start = pos + len(suffix)
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

from collections import defaultdict

if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        Str = input()
        obj = Solution()

        print(obj.maxFrequency(Str))

# } Driver Code Ends
