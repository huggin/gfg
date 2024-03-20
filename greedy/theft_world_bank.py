# User function Template for python3
import math


class Solution:
    def maximumProfit(self, N, C, w, p):
        # Code here
        gold = []
        e = 1e-6
        for i in range(N):
            a = int(math.sqrt(w[i]))
            if abs(a * a - w[i]) > e:
                gold.append((p[i] / w[i], w[i]))

        gold.sort(reverse=True)
        ans = 0
        for g in gold:
            if C >= g[1]:
                ans += g[1] * g[0]
                C -= g[1]
            else:
                ans += C * g[0]
                break
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, C = input().split()
        n = int(n)
        C = int(C)
        temp = list(map(int, input().split()))
        w = []
        p = []
        for i in range(2 * n):
            if (i % 2) == 0:
                w.append(temp[i])
            else:
                p.append(temp[i])
        ob = Solution()
        ans = ob.maximumProfit(n, C, w, p)
        print("{:.3f}".format(ans))
# } Driver Code Ends
