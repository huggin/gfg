# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


# return 1 in case of True and 0 in case of False
class Solution:
    def isAdditiveSequence(self, s):
        # code here
        n = len(s)

        def f(a, b, k, start=0):
            if k == n and start > 0:
                return 1
            c = str(a + b)

            if c == s[k : k + len(c)]:
                return f(b, a + b, k + len(c), 1)
            return 0

        for i in range(1, n):
            for j in range(1, n):
                a = int(s[0:i])
                b = int(s[i : i + j])
                if f(a, b, i + j):
                    return 1
        return 0


# {
# Driver Code Starts.

if __name__ == "__main__":
    sol = Solution()
    t = int(input())
    for _ in range(t):
        s = input()
        print(sol.isAdditiveSequence(s))

# } Driver Code Ends
