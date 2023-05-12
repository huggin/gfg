# User function Template for python3

# Back-end complete function Template for Python 3


class Solution:
    def ok(self, n):
        s = str(n)
        for i in range(1, len(s)):
            if s[i] < s[i - 1]:
                return False
        return True

    def find(self, N):
        # code here
        while N > 0:
            if self.ok(N):
                return N
            N -= 1

        return -1


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        print(ob.find(N))
# } Driver Code Ends
