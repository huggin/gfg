# User function Template for python3


class Solution:
    def findString(self, N, K):
        # code here
        if N == 1:
            return "".join(str(c) for c in range(K))
        s = set()

        def f(k, curr):
            if k == N:
                s.add(curr)
                return
            for i in range(K):
                curr = curr + str(i)
                f(k + 1, curr)
                curr = curr[:-1]

        curr = ""
        f(0, curr)

        self.ans = "0" * N
        s.remove(self.ans)

        def dfs(k):
            if k == K**N:
                return True
            for i in range(K):
                t = self.ans[-(N - 1) :] + str(i)
                if t in s:
                    s.remove(t)
                    self.ans += str(i)
                    if dfs(k + 1):
                        return True
                    self.ans = self.ans[0:-1]
                    s.add(t)

            return False

        dfs(1)
        return self.ans


# {
# Driver Code Starts
# Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, K = map(int, input().split())

        ob = Solution()
        ans = ob.findString(N, K)
        ok = 1
        for i in ans:
            if ord(i) < 48 or ord(i) > K - 1 + 48:
                ok = 0
        if not ok:
            print(-1)
            continue
        d = dict()
        i = 0
        while i + N - 1 < len(ans):
            d[ans[i : i + N]] = 1
            i += 1
        tot = pow(K, N)
        if len(d) == tot:
            print(len(ans))
        else:
            print(-1)
# } Driver Code Ends
