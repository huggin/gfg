# User function Template for python3


class Solution:
    def countSubarrays(self, a, n, L, R):
        # Complete the function
        ans = 0
        j = 0
        curr = 0
        for i in range(n):
            if a[i] > R:
                j = i + 1
                curr = 0
            elif a[i] >= L:
                curr = i - j + 1
            ans += curr

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n, l, r = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))
    ob = Solution()
    v = ob.countSubarrays(arr, n, l, r)
    print(v)

# } Driver Code Ends
