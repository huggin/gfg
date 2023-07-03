# User function Template for python3
class Solution:
    def maxIndexDiff(self, arr, n):
        # code here
        left = n * [0]
        right = n * [0]
        left[0] = arr[0]
        for i in range(1, n):
            left[i] = min(left[i - 1], arr[i])

        right[n - 1] = arr[n - 1]
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i + 1], arr[i])

        i, j, ans = 0, 0, 0
        while i < n and j < n:
            if left[i] <= right[j]:
                ans = max(ans, j - i)
                j += 1
            else:
                i += 1

        return ans


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    while t > 0:
        num = int(input())
        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.maxIndexDiff(arr, num))
        t -= 1
# } Driver Code Ends
