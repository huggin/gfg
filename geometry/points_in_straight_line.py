# Back-end complete function Template for Python 3
from collections import Counter


class Solution:
    def maxPoints(self, X, Y, N):
        # code here
        if N == 1:
            return 1
        ans = 0
        for i in range(N):
            cnt = Counter()
            temp = 0
            for j in range(N):
                if i == j:
                    continue
                if X[j] == X[i]:
                    temp += 1
                else:
                    cnt[(Y[j] - Y[i]) / (X[j] - X[i])] += 1

            ans = max(ans, cnt.most_common(1)[0][1] + 1, temp + 1)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        xarr = [int(x) for x in input().split()]
        yarr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.maxPoints(xarr, yarr, n)
        print(ans)
# } Driver Code Ends
