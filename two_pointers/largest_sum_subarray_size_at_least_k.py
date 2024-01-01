# User function Template for python3


class Solution:
    def maxSumWithK(self, a, n, k):
        # Code here
        ans = 0
        for i in range(k):
            ans += a[i]

        pre = [0] * n
        pre[0] = a[0]
        for i in range(1, n):
            pre[i] = max(a[i], pre[i - 1] + a[i])

        t = ans
        for i in range(k, n):
            t += a[i] - a[i - k]
            ans = max(ans, t)
            ans = max(ans, t + pre[i - k])

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        k = int(input())

        ob = Solution()
        print(ob.maxSumWithK(a, n, k))

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends
