# User function Template for python3

# arr[] : int input array of integers
# k : the quadruple sum required

from itertools import groupby


class Solution:
    def fourSum(self, arr, t):
        # code here
        arr.sort()
        ans = []
        n = len(arr)
        for i in range(n):
            a = arr[i]
            for j in range(i + 1, n):
                b = arr[j]
                k, l = j + 1, n - 1
                while k < l:
                    tot = a + b + arr[k] + arr[l]
                    if tot == t:
                        ans.append((a, b, arr[k], arr[l]))
                        k += 1
                        l -= 1
                    elif tot < t:
                        k += 1
                    else:
                        l -= 1

        ans.sort()
        ans = [key for key, _ in groupby(ans)]
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


# Main
if __name__ == "__main__":
    t = int(input())
    while t:
        t -= 1
        n, k = map(int, input().split())
        # print(n, k)
        a = list(map(int, input().strip().split()))[:n]
        # print(a)
        ob = Solution()
        ans = ob.fourSum(a, k)
        # print(ans)
        for v in ans:
            for u in v:
                print(u, end=" ")
            print("$", end="")
        if len(ans) == 0:
            print(-1, end="")
        print()


# } Driver Code Ends
