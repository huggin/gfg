# User function Template for python3


class Solution:
    def factorOrMultiple(self, N, X, A):
        # code here
        ans = 0
        for i in range(N):
            if A[i] % X == 0:
                ans |= A[i]
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, X = map(int, input().split())

        A = list(map(int, input().split()))

        ob = Solution()
        print(ob.factorOrMultiple(N, X, A))
# } Driver Code Ends
