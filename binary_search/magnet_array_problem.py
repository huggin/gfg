# User function Template for python3


class Solution:
    def calc(self, a, n, mid):
        ans = 0
        for i in range(n):
            if a[i] < mid:
                ans += 1 / (mid - a[i])
            else:
                ans -= 1 / (a[i] - mid)
        return ans

    def search(self, a, i, n):
        lo, hi = a[i], a[i + 1]
        while hi - lo > 1e-6:
            mid = (lo + hi) / 2
            v = self.calc(a, n, mid)
            if v > 0:
                lo = mid
            else:
                hi = mid

        return lo

    def nullPoints(self, n, a, getAnswer):
        # Your code goes here
        for i in range(n - 1):
            getAnswer[i] = self.search(a, i, n)


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        getAnswer = [0] * n
        ob = Solution()
        ob.nullPoints(n, a, getAnswer)

        for i in range(0, n - 1):
            print("{:.2f}".format(getAnswer[i]), end=" ")
        print()

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends
