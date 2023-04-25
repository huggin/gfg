# User function Template for python3
import bisect


class Solution:
    def construct(self, v, tl, tr):
        if tl == tr:
            self.t[v] = self.data[tl]
        else:
            tm = (tl + tr) // 2
            self.construct(2 * v + 1, tl, tm)
            self.construct(2 * v + 2, tm + 1, tr)
            self.t[v] = self.t[2 * v + 1] + self.t[2 * v + 2]

    def query(self, v, tl, tr, l, r):
        if l > r:
            return 0
        if l == tl and r == tr:
            return self.t[v]
        tm = (tl + tr) // 2
        return self.query(2 * v + 1, tl, tm, l, min(r, tm)) + self.query(
            2 * v + 2, tm + 1, tr, max(l, tm + 1), r
        )

    def update(self, v, tl, tr, pos, val):
        if tl == tr:
            self.t[v] += val
        else:
            tm = (tl + tr) // 2
            if pos <= tm:
                self.update(2 * v + 1, tl, tm, pos, val)
            else:
                self.update(2 * v + 2, tm + 1, tr, pos, val)
            self.t[v] = self.t[2 * v + 1] + self.t[2 * v + 2]

    def findSurpasser(self, arr, n):
        # code here
        temp = arr.copy()
        temp.sort()

        for i in range(n):
            idx = bisect.bisect(temp, arr[i])
            arr[i] = idx

        self.data = [0] * (n + 1)
        self.t = [0] * 4 * (n + 1)
        self.construct(0, 0, n)

        ans = [0] * n
        for i in range(n - 1, -1, -1):
            ans[i] = self.query(0, 0, n, arr[i] + 1, n)
            self.update(0, 0, n, arr[i], 1)

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
