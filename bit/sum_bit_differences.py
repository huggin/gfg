# User function Template for python3
class Solution:
    def sumBitDifferences(self, arr, n):
        # code here
        cnt = [0] * 32
        for a in arr:
            for i in range(32):
                if a & (1 << i):
                    cnt[i] += 1

        return sum(c * (n - c) for c in cnt) * 2


# {
# Driver Code Starts

# Initial Template for Python 3


if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.sumBitDifferences(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
