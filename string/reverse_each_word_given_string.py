# User function Template for python3


class Solution:
    def reverseWords(self, s):
        # code here
        words = s.split(".")
        return ".".join(w[::-1] for w in words)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ob = Solution()
        ans = ob.reverseWords(s)
        print(ans)
# } Driver Code Ends
