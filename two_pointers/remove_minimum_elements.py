# User function Template for python3
import bisect


class Solution:
    # Function to find the minimum number of elements to be removed.
    def minRemoval(self, arr):
        # code here
        arr.sort()
        j = 0
        n = len(arr)
        ma = 0
        for i in range(n):
            while j < n and arr[i] * 2 >= arr[j]:
                j += 1
            ma = max(ma, j - i)
        return n - ma


# {
# Driver Code Starts
def main():
    T = int(input())

    while T > 0:
        arr = list(
            map(int, input().strip().split())
        )  # Convert input to list of integers
        print(Solution().minRemoval(arr))
        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
