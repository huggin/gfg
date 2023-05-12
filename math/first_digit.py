# User function Template for python3
import math


class Solution:
    def firstDigit(self, arr, n):
        # code here
        s = 0.0
        for a in arr:
            s += math.log10(a)

        s = s - math.floor(s)

        return int(math.pow(10, s) + 1e-6)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.firstDigit(arr, n))
# } Driver Code Ends
