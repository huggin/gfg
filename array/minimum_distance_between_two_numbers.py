class Solution:
    def minDist(self, arr, n, x, y):
        ans = 100001
        idx = -100001
        idy = -100001
        for i in range(n):
            if arr[i] == x:
                idx = i
                ans = min(ans, abs(idx - idy))
            elif arr[i] == y:
                idy = i
                ans = min(ans, abs(idx - idy))

        return -1 if ans >= 100001 else ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        x, y = list(map(int, input().strip().split()))
        print(Solution().minDist(arr, n, x, y))


# } Driver Code Ends
