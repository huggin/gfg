# User function Template for python3


class Solution:
    def maxWater(self, arr, n):
        # code here
        left = [0] * n
        right = [0] * n
        left[0] = -1
        ma = arr[0]
        idx = 0
        for i in range(1, n):
            if arr[i] <= ma:
                left[i] = idx
            else:
                ma = arr[i]
                idx = i
                left[i] = -1

        right[n - 1] = -1
        ma = arr[n - 1]
        idx = n - 1
        for i in range(n - 2, -1, -1):
            if arr[i] <= ma:
                right[i] = idx
            else:
                ma = arr[i]
                idx = i
                right[i] = -1

        ans = 0
        for i in range(n):
            if left[i] == -1 or right[i] == -1:
                continue
            ans += min(arr[left[i]], arr[right[i]]) - arr[i]

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
        ans = ob.maxWater(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
