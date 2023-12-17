# User function Template for python3


class Solution:
    def gameOfXor(self, N, A):
        # code here
        ans = 0
        for i in range(N):
            left = i + 1
            right = N - i
            if left * right % 2 == 1:
                ans ^= A[i]

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().split()))

        ob = Solution()
        print(ob.gameOfXor(N, A))
# } Driver Code Ends
