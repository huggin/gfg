# User function Template for python3
import bisect


class Solution:
    def sum(self, bit, idx):
        ans = 0
        idx += 1
        while idx > 0:
            ans += bit[idx]
            idx -= idx & -idx
        return ans

    def update(self, bit, n, idx, val):
        idx += 1
        while idx < n:
            bit[idx] += val
            idx += idx & -idx

    def findSurpasser(self, arr, n):
        # code here
        temp = arr.copy()
        temp.sort()

        for i in range(n):
            idx = bisect.bisect(temp, arr[i])
            arr[i] = idx

        bit = [0] * (n + 1)
        ans = [0] * n
        for i in range(n - 1, -1, -1):
            inv = self.sum(bit, arr[i] - 1)
            ans[i] = n - 1 - i - inv
            self.update(bit, n + 1, arr[i], 1)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findSurpasser(arr, n)
        for xx in ans:
            print(xx, end=" ")
        print()
        tc -= 1

# } Driver Code Ends
