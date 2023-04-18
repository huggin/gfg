# User function Template for python3
class Solution:
    def wifiRange(self, N, S, X):
        # code here
        a = []
        for i in range(N):
            if S[i] == "1":
                a.append((i - X, i + X))

        if len(a) == 0 or a[0][0] > 0 or a[-1][1] < N - 1:
            return 0
        for i in range(1, len(a)):
            if a[i][0] > a[i - 1][1] + 1:
                return 0

        return 1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, X = map(int, input().strip().split())
        S = input()
        ob = Solution()
        ans = ob.wifiRange(N, S, X)
        if ans:
            print(1)
        else:
            print(0)

# } Driver Code Ends
