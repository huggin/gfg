class Solution:
    def minimumSum(self, s: str) -> int:
        # code here
        n = len(s)
        ans = 0
        prev = -1
        for i in range(n // 2):
            if s[i] == "?":
                if s[n - 1 - i] != "?":
                    if prev != -1:
                        ans += abs(prev - ord(s[n - 1 - i]))
                    prev = ord(s[n - 1 - i])
            elif s[n - 1 - i] == "?":
                if prev != -1:
                    ans += abs(prev - ord(s[i]))
                prev = ord(s[i])
            elif s[i] != s[n - 1 - i]:
                return -1
            else:
                if prev != -1:
                    ans += abs(prev - ord(s[i]))
                prev = ord(s[i])

        return ans * 2


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()

        obj = Solution()
        res = obj.minimumSum(s)

        print(res)


# } Driver Code Ends
