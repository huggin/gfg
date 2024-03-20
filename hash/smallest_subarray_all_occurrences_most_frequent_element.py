# User function Template for python3
from collections import Counter


class Solution:
    def smallestSubsegment(self, arr, n):
        # Complete the function
        c = Counter(arr)
        ma = c.most_common()[0][1]

        d = {}
        for i in range(n):
            if arr[i] not in d:
                d[arr[i]] = i

        ans = n + 1
        s, e = -1, -1
        for i in range(n - 1, -1, -1):
            if c[arr[i]] == ma and arr[i] in d and i - d[arr[i]] <= ans:
                ans = i - d[arr[i]]
                s = d[arr[i]]
                e = i
            if arr[i] in d:
                del d[arr[i]]
                # print(s, e, arr[s:e+1])

        return arr[s : e + 1]


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):

    n = int(input())
    arr = list(map(int, input().strip().split()))
    ob = Solution()
    res = ob.smallestSubsegment(arr, n)
    print(*res)


# } Driver Code Ends
