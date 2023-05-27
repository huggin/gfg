# User function Template for python3


class Solution:
    def find(self, i):
        while self.parent[i] != i:
            self.parent[i] = self.parent[self.parent[i]]
            i = self.parent[i]
        return i

    def union(self, i, j):
        pi = self.find(i)
        pj = self.find(j)
        ans = 0
        if self.count[pi] <= self.count[pj]:
            self.parent[pi] = pj
            self.count[pj] += self.count[pi]
            ans = pj
        else:
            self.parent[pj] = pi
            self.count[pi] += self.count[pj]
            ans = pi
        return ans

    def calc(self, groups):
        ans = 0
        for _, v in groups.items():
            ans += v * (v - 1) // 2
        return ans

    def maximumWeight(self, n, edges, q, queries):
        # code here
        edges.sort(key=lambda x: x[2])

        qi = []
        for i in range(q):
            qi.append((queries[i], i))
        qi.sort()

        self.parent = [i for i in range(n + 1)]
        self.count = [1] * (n + 1)

        ans = [0] * q
        i, j = 0, 0
        groups = {}
        while j < q:
            while i < n - 1 and edges[i][2] <= qi[j][0]:
                nr = self.union(edges[i][0], edges[i][1])
                if edges[i][0] in groups:
                    del edges[i][0]
                if edges[i][1] in groups:
                    del edges[i][1]

                groups[nr] = self.count[nr]
                i += 1
            ans[qi[j][1]] = self.calc(groups)
            j += 1
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        edges = [[0 for j in range(3)] for i in range(n - 1)]
        for i in range(n - 1):
            input_line = [int(x) for x in input().strip().split()]
            for j in range(3):
                edges[i][j] = input_line[j]

        q = int(input())
        queries = list(map(int, input().strip().split()))

        ob = Solution()
        ans = ob.maximumWeight(n, edges, q, queries)
        for i in ans:
            print(i, end=" ")
        print()


# } Driver Code Ends
