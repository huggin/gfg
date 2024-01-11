# User function Template for python3
import bisect


class Solution:
    def countPairs(self, arr, n):
        # Your code goes here
        a = [i * v for i, v in enumerate(arr)]
        a.sort()

        bit = [0] * (n + 1)

        def add(i):
            i += 1
            while i <= n:
                bit[i] += 1
                i += i & -i

        def get(i):
            ans = 0
            i += 1
            while i > 0:
                ans += bit[i]
                i -= i & -i
            return ans

        ans = 0
        for i in range(n - 1, -1, -1):
            j = bisect.bisect_left(a, i * arr[i])
            ans += get(j - 1)
            add(j)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.countPairs(a, n))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
