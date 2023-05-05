# User function Template for python3
class Solution:
    def numberOfConsecutiveOnes(ob, N):
        # code here
        dp1 = [0] * N
        dp2 = [0] * N
        dp1[0] = dp2[0] = 1

        for i in range(1, N):
            dp1[i] = dp2[i - 1]
            dp2[i] = dp1[i - 1] + dp2[i - 1]

        return (1 << N) - dp1[N - 1] - dp2[N - 1]


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        print(ob.numberOfConsecutiveOnes(N))
# } Driver Code Ends
