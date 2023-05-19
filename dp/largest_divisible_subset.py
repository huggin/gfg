# User function Template for python3


class Solution:
    def LargestSubset(self, n, arr):
        # Code here
        arr.sort()
        dp = [1] * n
        p = [-1] * n
        val = 0
        pos = 0
        for i in range(1, n):
            for j in range(i):
                if arr[i] % arr[j] == 0 and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    p[i] = j
            if val < dp[i]:
                val = dp[i]
                pos = i

        ans = []
        while pos != -1:
            ans.append(arr[pos])
            pos = p[pos]
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.LargestSubset(n, arr)
        isValidSeq, sz = 1, len(res)
        for i in range(sz):
            for j in range(i + 1, sz):
                if (res[i] % res[j] == 0) or (res[j] % res[i] == 0):
                    continue
                else:
                    isValidSeq = 0
                    break
        print(isValidSeq, sz)
# } Driver Code Ends
