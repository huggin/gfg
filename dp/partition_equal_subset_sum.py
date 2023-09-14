# User function Template for Python3


class Solution:
    def equalPartition(self, N, arr):
        # code here
        s = sum(arr)
        if s % 2 == 1:
            return 0
        dp = [0] * (s // 2 + 1)
        dp[0] = 1
        for a in arr:
            for i in range(s // 2, -1, -1):
                if i - a >= 0:
                    dp[i] += dp[i - a]

        return dp[s // 2] >= 1


# {
# Driver Code Starts
# Initial Template for Python3

import sys

input = sys.stdin.readline
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for it in range(N):
            arr[it] = int(arr[it])

        ob = Solution()
        if ob.equalPartition(N, arr) == 1:
            print("YES")
        else:
            print("NO")
# } Driver Code Ends
