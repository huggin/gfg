# User function Template for python3


class Solution:
    def countSort(self, arr, n, e):
        ans = [0] * n
        count = [0] * n
        for a in arr:
            count[a // e % n] += 1

        for i in range(1, n):
            count[i] += count[i - 1]

        for i in range(n - 1, -1, -1):
            ans[count[arr[i] // e % n] - 1] = arr[i]
            count[arr[i] // e % n] -= 1

        for i in range(n):
            arr[i] = ans[i]

    def sort(self, arr, n):
        # code here
        self.countSort(arr, n, 1)
        self.countSort(arr, n, n)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        N = int(input())
        arr = [int(x) for x in input().split()]

        solObj = Solution()

        solObj.sort(arr, N)
        for i in arr:
            print(i, end=" ")
        print()

# } Driver Code Ends
