# User function Template for python3


class Solution:
    def maxCoins(self, A, B, T, N):
        # code here
        a = [(B[i], A[i]) for i in range(N)]
        a.sort(reverse=True)
        # print(a)
        ans = 0
        for i in range(N):
            if a[i][1] <= T:
                ans += a[i][0] * a[i][1]
                T -= a[i][1]
            else:
                ans += a[i][0] * T
                break

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        T, N = map(int, input().split())
        A = list(map(int, input().split()))
        B = list(map(int, input().split()))

        ob = Solution()
        print(ob.maxCoins(A, B, T, N))
# } Driver Code Ends
