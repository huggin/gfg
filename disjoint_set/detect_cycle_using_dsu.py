class Solution:
    # Function to detect cycle using DSU in an undirected graph.
    def detectCycle(self, V, edge):
        # Code here
        edge.sort()
        id = list(c for c in range(V))
        count = [1] * V

        def root(u):
            while u != id[u]:
                id[u] = id[id[u]]
                u = id[u]
            return u

        def merge(u, v):
            pu = root(u)
            pv = root(v)
            if count[pu] < count[pv]:
                id[pu] = pv
                count[pv] += count[pu]
            else:
                id[pv] = pu
                count[pu] += count[pv]

        for i in range(len(edge)):
            if i != 0 and edge[i] == edge[i - 1]:
                continue
            if root(edge[i][0]) == root(edge[i][1]):
                return 1
            merge(edge[i][0], edge[i][1])

        return 0


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        V, E = map(int, input().split())
        edge = []
        for _ in range(E):
            u, v = map(int, input().split())
            edge.append((min(u, v), max(u, v)))

        if E > V - 1:
            print(1)
            continue
        obj = Solution()
        ans = obj.detectCycle(V, edge)
        print(ans)
    exit(0)
