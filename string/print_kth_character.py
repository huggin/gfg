# User function Template for python3


class Solution:
    def sort_cyclic_shifts(self, s):
        n = len(s)
        p = [0] * n
        c = [0] * n
        cnt = [0] * max(256, n)
        for ch in s:
            cnt[ord(ch)] += 1
        for i in range(1, 256):
            cnt[i] += cnt[i - 1]

        for i in range(n):
            idx = ord(s[i])
            cnt[idx] -= 1
            p[cnt[idx]] = i

        c[p[0]] = 0
        classes = 1
        for i in range(1, n):
            if s[p[i]] != s[p[i - 1]]:
                classes += 1
            c[p[i]] = classes - 1

        pn = [0] * n
        cn = [0] * n
        h = 0
        while (1 << h) < n:
            for i in range(n):
                pn[i] = p[i] - (1 << h)
                if pn[i] < 0:
                    pn[i] += n

            cnt = [0] * classes
            for i in range(n):
                cnt[c[pn[i]]] += 1
            for i in range(1, classes):
                cnt[i] += cnt[i - 1]

            for i in range(n - 1, -1, -1):
                cnt[c[pn[i]]] -= 1
                p[cnt[c[pn[i]]]] = pn[i]
            cn[p[0]] = 0
            classes = 1
            for i in range(n):
                curr_a, curr_b = c[p[i]], c[(p[i] + (1 << h)) % n]
                prev_a, prev_b = c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]
                if curr_a != prev_a or curr_b != prev_b:
                    classes += 1
                cn[p[i]] = classes - 1
            c, cn = cn, c
            h += 1

        return p

    def suffix_array(self, s):
        t = s + "$"
        sorted_shifts = self.sort_cyclic_shifts(t)
        return sorted_shifts[1:]

    def lcp(self, s, p):
        n = len(s)
        rank = [0] * n
        for i in range(n):
            rank[p[i]] = i

        k = 0
        lcp = [0] * n
        for i in range(n):
            if rank[i] == n - 1:
                k = 0
                continue
            j = p[rank[i] + 1]
            while i + k < n and j + k < n and s[i + k] == s[j + k]:
                k += 1
            lcp[rank[i]] = k
            if k:
                k -= 1

        return lcp

    def sum(self, n):
        return n * (n + 1) // 2

    def PrintKthCharacter(self, S, K):
        # code here
        p = self.suffix_array(S)
        l = self.lcp(S, p)
        n = len(S)

        for i in range(n):
            tot = self.sum(n - p[i]) - self.sum(l[i])

            if K <= tot:
                for j in range(l[i] + 1, n - p[i] + 1):
                    if K <= j:
                        return S[p[i] + K - 1]
                    else:
                        K -= j
            else:
                K -= tot

        return "$"


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S = input()
        K = int(input())

        ob = Solution()
        print(ob.PrintKthCharacter(S, K))
# } Driver Code Ends
