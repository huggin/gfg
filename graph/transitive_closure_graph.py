# User function Template for python3


class Solution:
    def transitiveClosure(self, N, graph):
        # code here
        for i in range(N):
            graph[i][i] = 1
            for j in range(N):
                for k in range(N):
                    graph[j][k] = graph[j][k] | (graph[j][i] & graph[i][k])

        return graph


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        graph = []
        for i in range(0, N):
            graph.append([int(j) for j in input().split()])
        ob = Solution()
        ans = ob.transitiveClosure(N, graph)
        for i in range(N):
            for j in range(N):
                print(ans[i][j], end=" ")
            print()
# } Driver Code Ends
