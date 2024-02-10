# User function Template for python3


class Solution:
    def recamanSequence(self, n):
        # code here
        a = [0] * (n)
        s = set()
        s.add(0)
        for i in range(1, n):
            c = a[i - 1] - i
            if c < 0 or c in s:
                c = a[i - 1] + i
            a[i] = c
            s.add(c)

        return a


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        ans = ob.recamanSequence(n)
        for i in range(n):
            print(ans[i], end=" ")
        print()
# } Driver Code Ends
