from typing import List


class Solution:
    def combine(self, v, v1, v2):
        for i in range(26):
            self.freq[v][i] = self.freq[v1][i] + self.freq[v2][i]

    def build(self, a, v, tl, tr):
        if tl == tr:
            self.freq[v][ord(a[tl]) - 97] = 1
        else:
            tm = (tl + tr) // 2
            self.build(a, v * 2, tl, tm)
            self.build(a, v * 2 + 1, tm + 1, tr)
            self.combine(v, v * 2, v * 2 + 1)

    def update(self, a, v, tl, tr, pos, val):
        if tl == tr:
            self.freq[v][ord(a[tl]) - 97] -= 1
            self.freq[v][ord(val) - 97] += 1
            a[pos] = val
        else:
            tm = (tl + tr) // 2
            if pos <= tm:
                self.update(a, v * 2, tl, tm, pos, val)
            else:
                self.update(a, v * 2 + 1, tm + 1, tr, pos, val)
            self.combine(v, v * 2, v * 2 + 1)

    def query(self, v, tl, tr, l, r):
        if l > tr or r < tl:
            return [0 for _ in range(26)]
        if l == tl and tr == r:
            return self.freq[v].copy()

        tm = (tl + tr) // 2
        f1 = self.query(v * 2, tl, tm, l, min(r, tm))
        f2 = self.query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r)
        for i in range(26):
            f1[i] += f2[i]
        return f1

    def easyTask(self, n, s, q, queries) -> List[int]:
        # code here
        ans = []
        a = list(s)
        self.freq = [[0 for _ in range(26)] for _ in range(4 * n)]
        self.build(a, 1, 0, n - 1)

        for query in queries:
            if query[0] == "1":
                self.update(a, 1, 0, n - 1, int(query[1]), query[2])
            else:
                cnt = self.query(1, 0, n - 1, int(query[1]), int(query[2]))
                k = int(query[3])

                for i in range(25, -1, -1):
                    if cnt[i] >= k:
                        ans.append(chr(97 + i))
                        break
                    else:
                        k -= cnt[i]

        return ans


# {
# Driver Code Starts
class IntArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input().strip()
        q = int(input())
        queries = []
        for i in range(q):
            quer = input().split()
            if quer[0] == "1":
                queries.append([quer[0], quer[1], quer[2]])
            else:
                queries.append([quer[0], quer[1], quer[2], quer[3]])

        ob = Solution()
        res = ob.easyTask(n, s, q, queries)

        IntArray().Print(res)


# } Driver Code Ends``
