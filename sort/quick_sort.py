# User function Template for python3


class Solution:
    # Function to sort a list using quick sort algorithm.
    def quickSort(self, arr, low, high):
        # code here
        if low >= high:
            return
        mid = self.partition(arr, low, high)
        self.quickSort(arr, low, mid - 1)
        self.quickSort(arr, mid + 1, high)

    def partition(self, arr, low, high):
        # code here
        j = low
        for i in range(low + 1, high + 1):
            if arr[i] <= arr[low]:
                j += 1
                arr[i], arr[j] = arr[j], arr[i]

        arr[low], arr[j] = arr[j], arr[low]
        return j


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        Solution().quickSort(arr, 0, n - 1)
        for i in range(n):
            print(arr[i], end=" ")
        print()

# } Driver Code Ends
