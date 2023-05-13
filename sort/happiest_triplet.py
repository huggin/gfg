# User function Template for python3


class Solution:
    def smallestDifferenceTriplet(self, a, b, c, n):
        # code here.
        a.sort()
        b.sort()
        c.sort()
        i, j, k = 0, 0, 0
        temp = [a[i], b[j], c[k]]
        val = 1000000
        ans = []
        while i < n and j < n and k < n:
            temp = [a[i], b[j], c[k]]
            mi, ma = 0, 0
            for idx in range(1, 3):
                if temp[idx] < temp[mi]:
                    mi = idx
                if temp[idx] > temp[ma]:
                    ma = idx

            if temp[ma] - temp[mi] < val:
                val = temp[ma] - temp[mi]
                ans = temp.copy()

            if mi == 0:
                i += 1
            elif mi == 1:
                j += 1
            else:
                k += 1

        ans.sort(reverse=True)
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


t = int(input())
for _ in range(0, t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    ob = Solution()
    ans = ob.smallestDifferenceTriplet(a, b, c, n)
    print(ans[0], ans[1], ans[2])

# } Driver Code Ends
