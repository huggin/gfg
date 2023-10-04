# User function Template for python3


class Solution:
    def count(self, s, k):
        cnt = [0] * 26
        unique = 0
        j = 0
        ans = 0
        n = len(s)
        for i in range(n):
            idx = ord(s[i]) - ord("a")
            cnt[idx] += 1
            if cnt[idx] == 1:
                unique += 1
            while unique > k:
                jdx = ord(s[j]) - ord("a")
                cnt[jdx] -= 1
                if cnt[jdx] == 0:
                    unique -= 1
                j += 1
            ans += j

        return ans

    def substrCount(self, s, k):
        if k == 0:
            return self.count(s, 1)
        return self.count(s, k - 1) - self.count(s, k)


# {
# Driver Code Starts
# Initial Template for Python 3

t = int(input())
for tc in range(t):
    s = input()
    k = int(input())
    ob = Solution()
    print(ob.substrCount(s, k))
# } Driver Code Ends
