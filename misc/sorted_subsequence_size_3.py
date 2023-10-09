# User function Template for python3


class Solution:
    def find3number(self, A, n):
        # code here
        a, b = A[0], -1
        a2 = -1
        for i in range(1, n):
            if A[i] < a:
                if b == -1:
                    a = A[i]
                elif a2 == -1 or A[i] < a2:
                    a2 = A[i]
            elif A[i] == a:
                if a2 != -1 and a2 < A[i]:
                    a, b = a2, A[i]
            elif b == -1:
                b = A[i]
            elif b < A[i]:
                return [a, b, A[i]]
            else:
                if a2 != -1:
                    a = a2
                    a2 = -1
                b = A[i]

        return []


# {
# Driver Code Starts
# Initial Template for Python 3

import sys

sys.setrecursionlimit(100000)


def isSubSeq(arr, lis, n, m):
    if m == 0:
        return True
    if n == 0:
        return False
    if arr[n - 1] == lis[m - 1]:
        return isSubSeq(arr, lis, n - 1, m - 1)
    return isSubSeq(arr, lis, n - 1, m)


t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    lis = Solution().find3number(arr, n)
    # print(lis)
    # print(isSubSeq(arr, lis, n, len(lis)))
    if len(lis) != 0 and len(lis) != 3:
        print(-1)
        continue
    if len(lis) == 0:
        print(0)
    elif lis[0] < lis[1] and lis[1] < lis[2] and isSubSeq(arr, lis, n, len(lis)):
        print(1)
    else:
        print(-1)

# } Driver Code Ends
