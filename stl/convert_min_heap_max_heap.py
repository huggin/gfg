# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def fix(self, arr, k, n):
        while k < n:
            child = k * 2 + 1
            if child >= n:
                break
            largest = child
            if child + 1 < n and arr[child] < arr[child + 1]:
                largest = child + 1
            arr[k], arr[largest] = arr[largest], arr[k]
            k = largest

    def convertMinToMaxHeap(self, N, arr):
        # Code here
        for i in range(N // 2 - 1, -1, -1):
            self.fix(arr, i, N)


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        ob.convertMinToMaxHeap(N, arr)
        for val in arr:
            print(val, end=" ")
        print()
# } Driver Code Ends
