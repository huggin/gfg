# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def replaceWithRank(self, N, arr):
        # Code here
        b = []
        for i in range(N):
            b.append((arr[i], i))

        b.sort()

        ans = [0] * N
        curr = 1
        for i in range(N):
            if i > 0 and b[i][0] != b[i - 1][0]:
                curr += 1
            ans[b[i][1]] = curr

        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.replaceWithRank(N, arr)
        for rank in res:
            print(rank, end=" ")
        print()
# } Driver Code Ends
