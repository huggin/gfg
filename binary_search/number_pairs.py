# User function Template for python3
import bisect


class Solution:
    def countPairs(self, X, Y, m, n):
        # code here
        X.sort()
        Y.sort()
        ans = 0
        for x in X:
            if x == 1:
                continue
            elif x == 2:
                idx = bisect.bisect_left(Y, 5)
                ans += n - idx
            elif x == 3:
                idx = bisect.bisect_left(Y, 2)
                ans += n - idx
                ans -= bisect.bisect(Y, 3) - bisect.bisect_left(Y, 3)
            else:
                idx = bisect.bisect_left(Y, x+1)
                ans += n - idx

        for y in Y:
            if y == 1:
                idx = bisect.bisect_left(X, 2)
                ans += m - idx

        return ans
# {
 # Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        m, n = list(map(int, input().strip().split()))
        X = list(map(int, input().strip().split()))
        Y = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.countPairs(X, Y, m, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
