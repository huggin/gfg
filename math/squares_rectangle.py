# User function Template for python3


class Solution:
    def minSquares(self, L, B):
        # code here
        def f(a, b):
            if a == b:
                return 1
            if a > b:
                return f(b, a)
            if a == 1:
                return b
            if b % a == 0:
                return b // a
            return b // a + f(b % a, a)

        return f(L, B) % int(1e9 + 7)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        L, B = [int(x) for x in input().split()]

        ob = Solution()
        print(ob.minSquares(L, B))
# } Driver Code Ends
