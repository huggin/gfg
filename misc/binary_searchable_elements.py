# User function Template for python3


class Solution:
    def binarySearchable(self, Arr, n):
        # code here
        left = [0] * n
        right = [100000] * n

        left[0] = Arr[0]
        for i in range(1, n):
            left[i] = max(left[i - 1], Arr[i])

        right[n - 1] = Arr[n - 1]
        for i in range(n - 2, -1, -1):
            right[i] = min(right[i + 1], Arr[i])

        ans = 0

        for i in range(n):
            if (
                i == 0
                and right[1] > Arr[i]
                or i == n - 1
                and left[n - 2] < Arr[n - 1]
                or left[i - 1] < Arr[i] < right[i + 1]
            ):
                ans += 1
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        Arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.binarySearchable(Arr, n))

# } Driver Code Ends
