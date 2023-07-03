# User function Template for python3


class Solution:
    def countSubArrayProductLessThanK(self, a, n, k):
        # Code here
        j = 0
        curr = 1
        ans = 0
        for i in range(n):
            curr *= a[i]
            while j < n and curr >= k:
                curr //= a[j]
                j += 1
            if j <= i:
                ans += i - j + 1

        return ans


# {
# Driver Code Starts

# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        n, k = [int(x) for x in input().strip().split()]
        arr = [int(x) for x in input().strip().split()]

        print(Solution().countSubArrayProductLessThanK(arr, n, k))

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends
