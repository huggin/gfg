# User function Template for python3
import math


class Solution:
    def LargestFraction(self, n, d):
        # Code here
        a, b = 1, 10000
        for i in range(2, 10001):
            s = i * n // d
            # print(i, s)
            for j in range(s, 0, -1):
                if j * d >= i * n:
                    continue
                if math.gcd(i, j) == 1:
                    if a * i < b * j:
                        a, b = j, i
                    break

        return [a, b]

    # n/d >= a/b
    # j/i > a/b, j * b > a * i


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, d = input().split()
        n = int(n)
        d = int(d)
        ob = Solution()
        ans = ob.LargestFraction(n, d)
        for _ in ans:
            print(_, end=" ")
        print()
# } Driver Code Ends
