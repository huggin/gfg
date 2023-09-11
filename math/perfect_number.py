# User function Template for python3


class Solution:
    def isPerfectNumber(self, N):
        # code here
        n = N
        sum = 1
        i = 2
        while i * i <= n:
            if n % i == 0:
                sum += i
                if i * i != n:
                    sum += n // i
            i += 1

        return 1 if sum == N and N != 1 else 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        print(ob.isPerfectNumber(N))
# } Driver Code Ends
