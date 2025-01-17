# User function Template for python3


class Solution:
    def minSwaps(self, arr):
        # Complete the function
        s = sum(arr)
        if s == 0:
            return -1
        ma = sum(arr[0:s])
        curr = ma
        for i in range(s, len(arr)):
            curr += arr[i] - arr[i - s]
            ma = max(ma, curr)

        return s - ma


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        a = list(map(int, input().strip().split()))  # Convert input to list of integers
        print(Solution().minSwaps(a))
        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
