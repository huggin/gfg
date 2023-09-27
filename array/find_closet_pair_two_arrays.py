# User function Template for python3


class Solution:
    def printClosest(self, arr, brr, n, m, x):
        # code here
        i, j = n - 1, 0
        ans = None
        off = -1
        while i >= 0 and j < m:
            d = arr[i] + brr[j]
            if off == -1 or abs(d - x) < off:
                off = abs(d - x)
                ans = [arr[i], brr[j]]
                if off == 0:
                    break
            if d < x:
                j += 1
            else:
                i -= 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

for _ in range(0, int(input())):
    n, m = map(int, input().split())
    arr = list(map(int, input().strip().split()))
    brr = list(map(int, input().strip().split()))
    x = int(input())
    ob = Solution()
    ans = ob.printClosest(arr, brr, n, m, x)
    print(abs(ans[0] + ans[1] - x))
# } Driver Code Ends
