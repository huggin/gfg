# User function Template for python3


class Solution:
    def isFit(self, arr, brr, n):
        # Complete the function
        arr.sort()
        brr.sort()
        return all(a <= b for a, b in zip(arr, brr))


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    brr = list(map(int, input().strip().split()))
    a = Solution()
    ans = a.isFit(arr, brr, n)
    if ans == True:
        print("YES")
    else:
        print("NO")
# } Driver Code Ends
