# User function Template for python3

# Back-end complete function Template for Python 3


class Solution:
    def sumOfDigits(self, n):
        ans = 0
        while n:
            ans += n % 10
            n //= 10
        return ans

    def RulingPair(self, arr, n):
        # Your code goes here
        d = {}
        ans = -1
        for a in arr:
            k = self.sumOfDigits(a)
            if k in d:
                ans = max(ans, a + d[k])
                d[k] = max(d[k], a)
            else:
                d[k] = a

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.RulingPair(arr, n))


# } Driver Code Ends
