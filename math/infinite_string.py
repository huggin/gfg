# User function Template for python3
class Solution:
    def posInfinite(self, pos):
        # code here
        s = "12345$54321$$12345$54321"
        start = 11
        mid = 2

        while start * 2 + mid < pos:
            start = start * 2 + mid
            mid += 1

        while pos > 11:
            if pos > start:
                pos -= start + mid
                if pos <= 0:
                    return "$"
            mid -= 1
            start = (start - mid) // 2

        return s[pos - 1]


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        pos = int(input())

        ob = Solution()
        print(ob.posInfinite(pos))
# } Driver Code Ends
