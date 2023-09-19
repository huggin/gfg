# User function Template for python3


class Solution:
    def rotate(self, N, D):
        # code here
        D %= 16
        a, b = N, N
        for i in range(D):
            if a & (1 << 15):
                a = (a << 1) & 0xFFFF | 1
            else:
                a <<= 1
            if b & 1:
                b = (b >> 1) | (1 << 15)
            else:
                b >>= 1

        return a, b


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, d = input().strip().split(" ")
        n, d = int(n), int(d)
        ob = Solution()
        ans = ob.rotate(n, d)
        print(ans[0])
        print(ans[1])
# } Driver Code Ends
