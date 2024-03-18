# User function Template for python3


class Solution:
    def distinct(self, M, N):
        # code here
        ans = set(M[0])
        for i in range(1, N):
            ans &= set(M[i])
        return len(ans)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        M = [[0] * N for i in range(N)]
        for itr in range(N * N):
            M[(itr // N)][itr % N] = int(arr[itr])

        ob = Solution()
        print(ob.distinct(M, N))
# } Driver Code Ends
