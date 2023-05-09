# User function Template for python3


class Solution:
    def maxSumBitonicSubArr(self, a, n):
        # Code here
        a[:] = map(int, a)
        left, right = [0] * n, [0] * n
        left[0] = a[0]
        for i in range(1, n):
            if a[i] > a[i - 1]:
                left[i] = left[i - 1] + a[i]
            else:
                left[i] = a[i]

        right[n - 1] = a[n - 1]
        for i in range(n - 2, -1, -1):
            if a[i] > a[i + 1]:
                right[i] = right[i + 1] + a[i]
            else:
                right[i] = a[i]

        ans = 0
        for i in range(n):
            ans = max(left[i] + right[i] - a[i], ans)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        a = [x for x in input().strip().split()]

        print(Solution().maxSumBitonicSubArr(a, n))

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends
