# User function Template for python3
from collections import defaultdict


class Solution:
    def sameOccurrence(self, arr, x, y):
        # code here
        d = defaultdict(int)
        d[0] = 1
        curr = 0
        ans = 0
        for a in arr:
            if a == x:
                curr -= 1
            if a == y:
                curr += 1
            ans += d[curr]
            d[curr] += 1
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        x = int(input().strip())
        y = int(input().strip())
        ob = Solution()
        ans = ob.sameOccurrence(arr, x, y)
        print(ans)
        tc -= 1
        print("~")

# } Driver Code Ends
