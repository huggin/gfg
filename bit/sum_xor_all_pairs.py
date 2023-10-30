# User function Template for python3


class Solution:
    def sumXOR(self, arr, n):
        # Complete the function
        cnt = [0] * 32
        for a in arr:
            for i in range(32):
                if a & (1 << i):
                    cnt[i] += 1

        ans = 0
        for i in range(32):
            ans += (n - cnt[i]) * cnt[i] * (1 << i)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):

    n = int(input())
    arr = list(map(int, input().strip().split()))
    ob = Solution()
    res = ob.sumXOR(arr, n)
    print(res)


# } Driver Code Ends
