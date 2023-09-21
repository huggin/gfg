# User function Template for python3
import bisect


class Solution:
    def find(self, arr, n, x):
        # code here
        a = bisect.bisect_left(arr, x)
        b = bisect.bisect_right(arr, x)
        if a == n or arr[a] != x:
            return [-1, -1]
        return [a, b - 1]


# {
# Driver Code Starts
t = int(input())
for _ in range(0, t):
    l = list(map(int, input().split()))
    n = l[0]
    x = l[1]
    arr = list(map(int, input().split()))
    ob = Solution()
    ans = ob.find(arr, n, x)
    print(*ans)
# } Driver Code Ends
