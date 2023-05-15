# User function Template for python3


class Solution:
    def socialNetwork(self, arr, N):
        # code here
        links = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
        for i in range(N - 1):
            links[i + 2][arr[i]] = 1
            for j in range(1, arr[i]):
                if links[arr[i]][j] != 0:
                    links[i + 2][j] = links[i + 2][arr[i]] + links[arr[i]][j]

        ans = []
        for i in range(2, N + 1):
            for j in range(1, i):
                if links[i][j] != 0:
                    ans.append(i)
                    ans.append(j)
                    ans.append(links[i][j])

        return " ".join(str(a) for a in ans)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))

        ob = Solution()
        print(ob.socialNetwork(arr, N))
# } Driver Code Ends
