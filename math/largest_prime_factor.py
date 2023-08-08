# User function Template for python3


class Solution:
    def largestPrimeFactor(self, N):
        # code here
        ans = 1
        i = 2
        while i * i <= N:
            while N % i == 0:
                N //= i
                ans = max(ans, i)
            i += 1

        return max(ans, N)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        print(ob.largestPrimeFactor(N))
# } Driver Code Ends
