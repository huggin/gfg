# User function Template for python3


class Solution:
    def swapBits(self, X, P1, P2, N):
        mask = (1 << N) - 1
        a = (X & (mask << P1)) >> P1
        b = (X & (mask << P2)) >> P2
        X &= ~(mask << P1) & ~(mask << P2)
        X |= a << P2 | b << P1

        return X


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        obj = Solution()
        X, P1, P2, N = map(int, input().split())
        print(obj.swapBits(X, P1, P2, N))


# } Driver Code Ends
