# User function Template for python3
from collections import Counter


class Solution:
    def findUniquePair(self, arr, n):
        # Complete the function
        c = Counter()
        for a in arr:
            c[a] += 1

        ans = []
        for k, v in c.most_common():
            if v == 1:
                ans.append(k)

        if ans[0] > ans[1]:
            ans[0], ans[1] = ans[1], ans[0]
        return ans


# {
# Driver Code Starts

for _ in range(0, int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    ob = Solution()
    v = ob.findUniquePair(arr, n)
    print(*v)

# } Driver Code Ends
