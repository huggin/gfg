# User function Template for python3


class Solution:
    def graycode(self, n):
        g = [x ^ (x >> 1) for x in range(1 << n)]
        return ["{:0{n}b}".format(x, n=n) for x in g]


# {
# Driver Code Starts
# Initial Template for Python 3
import math


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        ob = Solution()
        l = ob.graycode(n)

        for x in l:
            print(x, end=" ")

        print()

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends
