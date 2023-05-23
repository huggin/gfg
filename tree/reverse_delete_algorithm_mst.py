# User function Template for python3


class Solution:
    def RevDelMST(self, Arr, V, E):
        # code here
        g = [[0 for _ in range(V)] for _ in range(V)]
        edges = []
        for i in range(E):
            g[Arr[i * 3]][Arr[i * 3 + 1]] = Arr[i * 3 + 2]
            g[Arr[i * 3 + 1]][Arr[i * 3]] = Arr[i * 3 + 2]
            edges.append((Arr[i * 3], Arr[i * 3 + 1], Arr[i * 3 + 2]))

        edges.sort(reverse=True, key=lambda x: x[2])

        mst = set()

        for edge in edges:
            u, v, weight = edge
            g[u][v] = 0
            g[v][u] = 0

            visited = [False] * V
            stack = [0]
            while stack:
                curr_vertex = stack.pop()
                visited[curr_vertex] = True

                for neighbor in range(V):
                    if g[curr_vertex][neighbor] != 0 and not visited[neighbor]:
                        stack.append(neighbor)

            if not all(visited):
                mst.add((u, v, weight))
                g[u][v] = weight
                g[v][u] = weight

        ans = 0
        for _, _, w in mst:
            ans += w

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        V, E = map(int, input().split())
        Arr = list(map(int, input().split()))

        ob = Solution()
        print(ob.RevDelMST(Arr, V, E))
# } Driver Code Ends
