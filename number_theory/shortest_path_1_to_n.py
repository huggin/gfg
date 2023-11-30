# User function Template for python3


class Solution:
    def minimumStep(self, n):
        # complete the function here
        ans = 0
        while n > 0:
            if n % 3 == 0:
                ans += 1
                n //= 3
            else:
                ans += n % 3
                n -= n % 3
        return ans - 1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.minimumStep(n))
# } Driver Code Ends
