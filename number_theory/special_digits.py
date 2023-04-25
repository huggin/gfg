from collections import deque


def inv(n, m):
    k = m - 2
    ans = 1
    while k > 0:
        if k & 1 == 1:
            ans = (ans * n) % m
        n = (n * n) % m
        k >>= 1
    return ans


class Solution:
    def bestNumbers(self, N: int, A: int, B: int, C: int, D: int) -> int:
        # code here
        M = 1000000007
        fact = [1]
        for i in range(1, N+1):
            fact.append(fact[-1] * i % M)
        if A > B:
            A, B = B, A
        if C > D:
            C, D = D, C

        mi = A * N
        ma = B * N

        s = []
        q = deque()
        q.append(C)
        if D != C:
            q.append(D)
        while len(q) > 0:
            curr = q.popleft()
            if mi <= curr <= ma:
                s.append(curr)
            else:
                if curr * 10 + C <= ma:
                    q.append(curr * 10 + C)
                if D != C and curr * 10 + D <= ma:
                    q.append(curr * 10 + D)

        if A == B:
            if mi in s:
                return pow(2, N, M)
            else:
                return 0

        ans = 0
        for num in s:
            x = (ma - num) // (B - A)
            if x * (B-A) != (ma - num):
                continue
            ans = (ans + fact[N] * inv(fact[x] * fact[N-x] % M, M)) % M

        return ans


# {
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        N = int(input())

        A = int(input())

        B = int(input())

        C = int(input())

        D = int(input())

        obj = Solution()
        res = obj.bestNumbers(N, A, B, C, D)

        print(res)


# } Driver Code Ends
