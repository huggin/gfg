# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3
import bisect


class Solution:
    def ValidPair(self, a, n):
        # Your code goes here
        a.sort()
        ans = 0
        for i in range(n):
            if a[i] < 0:
                ans += n - bisect.bisect(a, -a[i])
            else:
                ans += n - (i + 1)
        return ans


# {
# Driver Code Starts.

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        array = list(map(int, input().strip().split()))
        obj = Solution()
        ans = obj.ValidPair(array, n)
        print(ans)


# } Driver Code Ends
