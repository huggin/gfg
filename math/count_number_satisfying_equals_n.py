# User function Template for python3


class Solution:
    def sum(self, n):
        ans = 0
        while n > 0:
            ans += n % 10
            n //= 10
        return ans

    def countOfNumbers(self, N):
        # code here
        ans = 0
        for i in range(N - 1, N - 100, -1):
            if i <= 0:
                break
            s1 = self.sum(i)
            s2 = self.sum(s1)
            if s1 + s2 + i == N:
                ans += 1
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        print(ob.countOfNumbers(N))
# } Driver Code Ends
