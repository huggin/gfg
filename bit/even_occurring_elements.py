# User function Template for python3
from collections import Counter


class Solution:
    def repeatingEven(self, arr, n):
        # code here
        c = Counter(arr)
        ans = [k for k in c if c[k] % 2 == 0]
        ans.sort()
        if len(ans) == 0:
            return [-1]
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.repeatingEven(arr, n)
        for xx in ans:
            print(xx, end=" ")
        print()
        tc -= 1

# } Driver Code Ends
