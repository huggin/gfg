# User function Template for python3


class Solution:
    def longestKSubstr(self, s, k):
        # code here
        j = 0
        n = len(s)
        ans = -1
        cnt = [0 for _ in range(26)]
        for i in range(n):
            d = ord(s[i]) - ord("a")
            cnt[d] += 1
            if cnt[d] == 1:
                k -= 1

            while k < 0:
                cnt[ord(s[j]) - ord("a")] -= 1
                if cnt[ord(s[j]) - ord("a")] == 0:
                    k += 1
                j += 1

            if k == 0:
                ans = max(ans, i - j + 1)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        s = input()
        k = int(input())

        solObj = Solution()

        ans = solObj.longestKSubstr(s, k)

        print(ans)

# } Driver Code Ends
