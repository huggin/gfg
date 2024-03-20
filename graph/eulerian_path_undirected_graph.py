# User function Template for Python3


class Solution:
    def eulerPath(self, N, graph):
        # code here
        odd = 0
        for v in graph:
            if v.count(1) % 2:
                odd += 1

        return 1 if odd == 0 or odd == 2 else 0


# {
# Driver Code Starts
# Initial Template for Python3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input().strip())
        graph = []
        for i in range(N):
            graph.append(list(map(int, input().strip().split())))

        ob = Solution()
        print(ob.eulerPath(N, graph))
# } Driver Code Ends
