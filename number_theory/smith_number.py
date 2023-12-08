# User function Template for python3


class Solution:
    def smithNum(self, n):
        # code here
        def prime(n):
            i = 2
            while i * i <= n:
                if n % i == 0:
                    return False
                i += 1
            return True

        def f(n):
            i = 2
            ans = 0
            while i * i <= n:
                cnt = 0
                while n % i == 0:
                    cnt += 1
                    n //= i
                ans += cnt * g(i)
                i += 1
            if n != 1:
                ans += g(n)
            return ans

        def g(n):
            ans = 0
            while n > 0:
                ans += n % 10
                n //= 10
            return ans

        return 1 if (not prime(n)) and f(n) == g(n) else 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        print(ob.smithNum(n))
# } Driver Code Ends
